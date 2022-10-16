#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const ll INF = 1e14 + 7;

int a[1000006], b[1000006], st[10000007], prime[1000006], psz;
int pq[10000007][2];
void dfs(const vector<pi> & v,int i,int p,int ai) {
	if(i==v.size()){
		if(pq[p][0] == -1) pq[p][0] = ai;
        else if (pq[p][1] == -1) pq[p][1] = ai;
		return;
	}
	for (int j = 0; j <= v[i].S; j++, p *= v[i].F)
		dfs(v,i+1,p,ai);
}
int32_t main()
{
	IO_OP;
	memset(pq,-1,sizeof pq);
	int n;
	cin >> n;
	for(int i=0;i<n;++i)
		cin >> a[i];
    iota(b,b+n,0);
    sort(b,b+n,[](int i,int j){return a[i]<a[j];});
	for (int i = 2; i < 10000007; ++i) {
		if (!st[i]) prime[psz++] = i, st[i] = i;
		for (int j = 0; j < psz && i * 1ll * prime[j] < 10000007; ++j) {
			st[i * prime[j]] = prime[j];
			if (i % prime[j] == 0) break;
		}
	}
	for(int i=0;i<n;i++) {
		int x=a[b[i]];
        if (i >= 2 && x == a[b[i-2]])
            continue;
		vector<pi> v; 
		while(x>1) {
			int p = st[x];
			int c = 0;
			while (x % p == 0)
				x /= p, ++c;
			v.EB(p,c);
		}
		dfs(v,0,1,b[i]);
	}
	ll ans = INF, ii, jj;
	for(int i=1;i<10000007;++i) {
		if(pq[i][1] == -1) continue;
        ll w = a[pq[i][0]] * 1ll * a[pq[i][1]] / i;
        if (w < ans) {
			ans = w;
			ii = pq[i][0], jj = pq[i][1];
		}
	}
	if(ii > jj) swap(ii, jj);
	cout << ii+1 << " " << jj+1	 << endl;
}