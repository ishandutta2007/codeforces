#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define pii pair<int, int>
#define M 1000000007
#define all(a) a.begin(), a.end()

const int maxn = 100005;
const int B = 50;
char s[maxn];
string a[maxn];
int lcp[maxn];
set<int> st;
int n, q;
int tmp_mx, tmp_suf[B + 1];

struct SegmentTree{
	int pre[B + 1][maxn * 2 + 1], suf[B + 1][maxn * 2 + 1];
	int mx[maxn * 2 + 1];

	inline int getID(int l, int r){
		return (l < r) | (l + r);
	}

	inline void update(int t, int l, int r){
		int mid = (l + r) >> 1, lt = getID(l, mid), rt = getID(mid + 1, r);
		mx[t] = max(mx[lt], mx[rt]);
		for(int i = 1; i <= B; ++i){
			pre[i][t] = pre[i][lt] + (pre[i][lt] == mid - l + 1 ? pre[i][rt] : 0);
			suf[i][t] = suf[i][rt] + (suf[i][rt] == r - mid ? suf[i][lt] : 0);
			if(suf[i][lt] && pre[i][rt]) 
				mx[t] = max(mx[t], (suf[i][lt] + pre[i][rt] + 1) * i);
		}
	}

	void build(int l, int r){
		int t = getID(l, r);
		if(l == r){
			for(int i = 1; i <= B; ++i)
				pre[i][t] = suf[i][t] = lcp[l] >= i;
			mx[t] = max(lcp[l] * 2, (int)a[l].size());
			return;
		}
		int mid = (l + r) >> 1;
		build(l, mid), build(mid + 1, r);
		update(t, l, r);
	}

	void modify(int l, int r, int x){
		int t = getID(l, r);
		if(l == r){
			for(int i = 1; i <= B; ++i)
				pre[i][t] = suf[i][t] = lcp[l] >= i;
			mx[t] = max(lcp[l] * 2, (int)a[l].size());
			return;
		}
		int mid = (l + r) >> 1;
		if(x <= mid) modify(l, mid, x);
		else modify(mid + 1, r, x);
		update(t, l, r);
	}
	void ask(int l, int r, int x, int y){
		int t = getID(l, r);
		if(x <= l && y >= r){
			for(int i = 1; i <= B; ++i){
				if(tmp_suf[i] || pre[i][t]) tmp_mx = max(tmp_mx, (tmp_suf[i] + pre[i][t] + 1) * i);
				tmp_suf[i] = suf[i][t] + (suf[i][t] == r - l + 1 ? tmp_suf[i] : 0);
			}
			tmp_mx = max(tmp_mx, mx[t]);
			return;
		}
		int mid = (l + r) >> 1;
		if(x <= mid) ask(l, mid, x, y);
		if(y > mid) ask(mid + 1, r, x, y);
	}
}tree;

inline int strlcp(string &a, string &b){
	int tmp = 0;
	while(tmp < a.size() && tmp < b.size() && a[tmp] == b[tmp]) ++tmp;
	return tmp;
}

int work(vector<int> &v){
	int m = v.size();
	stack<int> sta;
	vector<int> L(m);
	for(int i = 0; i < m; ++i){
		while(!sta.empty() && v[i] <= v[sta.top()]) sta.pop();
		L[i] = sta.empty() ? -1 : sta.top();
		sta.push(i);
	}
	while(!sta.empty()) sta.pop();
	int mx = 0;
	for(int i = m - 1; i >= 0; --i){
		while(!sta.empty() && v[i] <= v[sta.top()]) sta.pop();
		int R = sta.empty() ? m : sta.top();
		mx = max(mx, (R - L[i]) * v[i]);
		sta.push(i);
	}
	return mx;
}

int work(int l, int r){
	auto lt = st.lower_bound(l), rt = st.upper_bound(r);
	if(lt == rt) return 0;
	vector<int> v; v.pb(lcp[*lt]);
	int last = *lt, res = 0;
	++lt;
	while(lt != rt){
		if(*lt != last + 1) res = max(res, work(v)), v.clear();
		last = *lt;
		v.pb(lcp[*lt]); ++lt;
	}
	return max(res, work(v));
}

int main(){
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; ++i){
		scanf("%s", s);
		a[i] = s;
	}
	for(int i = 1; i <= n - 1; ++i){
		lcp[i] = strlcp(a[i], a[i + 1]);
		if(lcp[i] > B) st.insert(i);
	}
	if(n > 1) tree.build(1, n - 1);
	
	while(q--){
		static int ty, l, r, x;
		scanf("%d", &ty);
		if(ty == 1){
			scanf("%d%d", &l, &r);
			tmp_mx = 0;
			memset(tmp_suf, 0, sizeof(tmp_suf));
			if(l < r) tree.ask(1, n - 1, l, r - 1);
			int ans = max((int)a[r].size(), tmp_mx);
			ans = max(ans, work(l, r - 1));
			printf("%d\n", ans);
		}else{
			scanf("%d%s", &x, s);
			a[x] = s;
			if(x > 1){
				if(lcp[x - 1] > B) st.erase(x - 1);
				lcp[x - 1] = strlcp(a[x - 1], a[x]);
				tree.modify(1, n - 1, x - 1);
				if(lcp[x - 1] > B) st.insert(x - 1);
			}
			if(x < n){
				if(lcp[x] > B) st.erase(x);
				lcp[x] = strlcp(a[x], a[x + 1]);
				tree.modify(1, n - 1, x);
				if(lcp[x] > B) st.insert(x);
			}
		}
	}
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}