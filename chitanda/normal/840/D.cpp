#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define M 1000000007
#define all(a) a.begin(), a.end()

const int INF = 1e9;
int num[4], cnt[4];
vector<int> q[300100];
int a[300100];
int n, Q;
int g[300100];

struct node{
	int num[4], cnt[4];
	node(){
		memset(num, 0, sizeof(num));
		memset(cnt, 0, sizeof(cnt));
	}
}tr[1200100], res;

inline int get(int x, int l, int r){
	return upper_bound(q[x].begin(), q[x].end(), r)
					- lower_bound(q[x].begin(), q[x].end(), l);
}

pair<int, int> v[10];
inline node merge(node p, node q){
	for(int i = 0; i < 4; ++i)
		if(q.cnt[i]){
			int j = 0, mn = 0;
			for(j = 0; j < 4; ++j){
				if(p.cnt[j] < p.cnt[mn]) mn = j;
				if(p.num[j] == q.num[i]) break;
			}
			if(j < 4){
				p.cnt[j] += q.cnt[i];
				continue;
			}
			if(p.cnt[mn] < q.cnt[i]){
				int tmp = p.cnt[mn];
				for(j = 0; j < 4; ++j)
					p.cnt[j] -= tmp;
				p.num[mn] = q.num[i];
				p.cnt[mn] = q.cnt[i] - tmp;
			}else{
				for(j = 0; j < 4; ++j)
					p.cnt[j] -= q.cnt[i];
			}
		}
	return p;
}

void build(int t, int l, int r){
	if(l == r){
		tr[t].num[0] = a[l], tr[t].cnt[0] = 1;
		return;
	}
	int mid = (l + r) >> 1;
	build(t << 1, l, mid);
	build((t << 1) | 1, mid + 1, r);
	tr[t] = merge(tr[t << 1], tr[(t << 1) | 1]);
}

void query(int t, int l, int r, int x, int y){
	if(x <= l && y >= r){
		res = merge(res, tr[t]);
		return;
	}
	int mid = (l + r) >> 1;
	if(x <= mid) query(t << 1, l, mid, x, y);
	if(y > mid) query((t << 1) | 1, mid + 1, r, x, y);
}

int main(){
	//freopen("d.in", "r", stdin);
	//freopen("d.out", "w", stdout);
	scanf("%d%d", &n, &Q);
	for(int i = 1; i <= n; ++i){
		scanf("%d", a + i);
		q[a[i]].pb(i);
	}
	build(1, 1, n);
	while(Q--){
		int l, r, k;
		scanf("%d%d%d", &l, &r, &k);
		memset(res.num, 0, sizeof(res.num));
		memset(res.cnt, 0, sizeof(res.cnt));
		query(1, 1, n, l, r);
		int ans = INF;
		for(int i = 0; i < 4; ++i)
			if(get(res.num[i], l, r) > (r - l + 1) / k)
				ans = min(ans, res.num[i]);
		printf("%d\n", ans == INF ? -1 : ans);
	}

	return 0;
}