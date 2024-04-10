#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, j, n) for(int i = j; i <= n; ++i)
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl;
#define ios cin.tie(0); ios_base::sync_with_stdio(0)
 
 
using namespace std;

const int nax = 1e5 + 111;
const int P = 300;	

int n, m, q;
int a, b, k;
char c;
vector <int> v[nax], si;
int t[nax];

unordered_map <int, ll> zbior[nax], sack;

ll add[nax];
ll sum[nax];
bool big[nax];

int res[P + 1][nax];
int id[nax];
int fre = 0;

int main() {
	scanf("%d %d %d", &n, &m, &q);
	FOR(i, 1, n)
		scanf("%d", t + i);
	FOR(i, 1, m) {
		scanf("%d", &k);
		FOR(j, 1, k) {
			scanf("%d", &a);
			sum[i] += t[a];
			zbior[i][a] = 1;
			v[i].pb(a);
		}
		big[i] = (k >= P);
		if(big[i]) {
			si.pb(i);
			id[i] = fre++;
		}
	}
	
	for(auto it : si) {
		FOR(i, 1, m) {
			int x = it;
			int y = i;
			if(ss(zbior[x]) > ss(zbior[y]))
				swap(x, y);
			int ans = 0;
			for(auto it : v[x])
				ans += zbior[y].find(it) != zbior[y].end();
			res[id[it]][i] = ans;
		}
	}
	
	while(q--) {
		scanf(" %c", &c);
		scanf("%d", &a);
		if(c == '+') {
			scanf("%d", &b);
			if(big[a]) {
				add[a] += b;
			}
			else {
				for(auto it : v[a])
					sack[it] += b;
				for(auto it : si) {
					sum[it] += (ll) res[id[it]][a] * b;
				}
			}
		}
		else {
			ll ans = sum[a];
			for(auto it : si)
				ans += (ll) res[id[it]][a] * add[it];
			if(!big[a]) {
				for(auto it : v[a])
					ans += sack[it];
			}
			printf("%lld\n", ans);
		}
	}
		
	
	
	
	
	return 0;
}