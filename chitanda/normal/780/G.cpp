#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define M 1000000007
#define all(a) a.begin(), a.end()
#define ls t << 1
#define rs t << 1 | 1
#define lss ls, l, mid
#define rss rs, mid + 1, r

const int INF = (2e9) + 7;
const int maxn = 100100;
int h, w, n;
stack<pair<int, int> > q[maxn];
int u[maxn], l[maxn], r[maxn], s[maxn], p[maxn];
pair<int, int> minh[maxn << 2];
int cnt;

void build(int t, int l, int r){
	minh[t] = mkp(h + 1, l);
	if(l == r){
		q[l].push(mkp(h + 1, 1));
		return;
	}
	int mid = (l + r) >> 1;
	build(lss);
	build(rss);
}

void insert(int t, int l, int r, int x, int h, int num){
	if(l == r){
		q[l].push(mkp(h, num));
		minh[t] = mkp(h, l);
		return;
	}
	int mid = (l + r) >> 1;
	if(x <= mid) insert(lss, x, h, num);
	else insert(rss, x, h, num);
	minh[t] = min(minh[ls], minh[rs]);
}

void ask(int t, int l, int r, int x, int y, int lim){
	if(minh[t].fi > lim) return;
	if(l == r){
		while(!q[l].empty() && q[l].top().fi <= lim){
			(cnt += q[l].top().se) >= M && (cnt -= M);
			q[l].pop();
		}
		minh[t] = q[l].empty() ? mkp(INF, 0) : mkp(q[l].top().fi, l);
		return;
	}
	int mid = (l + r) >> 1;
	if(x <= mid) ask(lss, x, y, lim);
	if(y > mid) ask(rss, x, y, lim);
	minh[t] = min(minh[ls], minh[rs]);
}

int main(){
	//freopen("c.out", "w", stdout);
	scanf("%d%d%d", &h, &w, &n);
	for(int i = 1; i <= n; ++i){
		scanf("%d%d%d%d", u + i, l + i, r + i, s + i);
		p[i] = i;
	}
	sort(p + 1, p + n + 1, [](int i, int j) { return u[i] > u[j]; });
	build(1, 1, w);
	for(int i = 1; i <= n; ++i){
		int x = p[i];
		cnt = 0;
		ask(1, 1, w, l[x], r[x], u[x] + s[x]);
		if(cnt){
			(l[x] == 1 || r[x] == w) && (cnt += cnt) >= M && (cnt -= M);
			if(r[x] < w) insert(1, 1, w, r[x] + 1, u[x], cnt);
			if(l[x] > 1) insert(1, 1, w, l[x] - 1, u[x], cnt);
		}
		/*
		printf("%d %d %d %d\n", u[x], l[x], r[x], s[x]);
		for(int i = 1; i <= w; ++i){
			printf("row %d: ", i);
			auto qq = q[i];
			while(!qq.empty()){
				printf("h=%d,num=%d ", qq.top().fi, qq.top().se);
				qq.pop();
			}
			printf("\n");
		}
		printf("\n\n\n\n");
		*/
	}
	int res = 0;
	for(int i = 1; i <= w; ++i)
		while(!q[i].empty()) (res += q[i].top().se) >= M && (res -= M), q[i].pop();
	printf("%d\n", res);
	/*	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	*/
	return 0;
}