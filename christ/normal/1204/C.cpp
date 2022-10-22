#include<bits/stdc++.h>
using namespace std;
char _;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template <typename t> void scan (t& x) {do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0);}
template <typename t, typename ...r> void scan (t& x, r&... xs) {scan(x); scan(xs...);}
const int MN = 103;
int adj[MN][MN];
int sp[MN][MN];
bool good[MN];
vector<int> p,v;
int main () {
	int n,a;
	scanf ("%d",&n);
	for (int i = 1; i <= n; i++) {
		getchar();
		for (int j = 1; j <= n; j++) {
			adj[i][j] = getchar() == '1';
			if (i == j) sp[i][j] = 0;
			else if (adj[i][j]) sp[i][j] = 1;
			else sp[i][j] = 100000;
			
		}
	}
	int k;
	scanf ("%d",&k);
	for (int i = 1; i <= k; i++) {
		scanf ("%d",&a);
		good[a] = 1;
		p.push_back(a);
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				sp[i][j] = min(sp[i][j],sp[i][k] + sp[k][j]);
			}
		}
	}
	int last = p[0];
	v.push_back(p[0]);
	for (int i = 2; i < k; i++) {
		int cur = p[i];
		if (sp[last][cur] == sp[last][p[i-1]] + sp[p[i-1]][cur]) continue;
		last = p[i-1];
		v.push_back(p[i-1]);
	}
	if (v.back() != p[k-1]) v.push_back(p[k-1]);
	printf ("%d\n",v.size());
	for (int i : v) printf ("%d ",i);
	printf ("\n");
	return 0;
}