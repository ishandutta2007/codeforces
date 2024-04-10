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

const int nax = 1e7 + 111;

int n, k;
int a[nax];
ll suf[nax];
vector <pair<int, int>> v, u;

bool fun(int pos) {
	return suf[pos] >= k;
}

int main() {
	scanf("%d%d", &n, &k);
	FOR(i, 1, n)
		scanf("%d", &a[i]);
	
	FOR(i, 1, n) {
		v.clear();
		v.pb(mp(a[i], 1));
		while(ss(v)) {
			/*for(auto it : v)
				cout << it.fi << " " << it.se << endl;
			cout << endl;
			*/
			u.clear();
			for(auto it : v) {
				if(it.fi == 1)
					suf[1] += it.se;
				else {
					int l = (it.fi + 1) / 2;
					suf[it.fi] += it.se;
					suf[l] -= it.se;
					pair<int, int> a = mp(it.fi / 2, it.se);
					pair<int, int> b = mp((it.fi + 1) / 2, it.se);
					bool ok = 0;
					for(auto &j : u)
						if(j.fi == a.fi) {
							j.se += a.se;
							ok = 1;
							break;
						}
					if(!ok)
						u.pb(a);
					ok = 0;
					for(auto &j : u)
						if(j.fi == b.fi) {
							j.se += b.se;
							ok = 1;
							break;
						}
					if(!ok)
						u.pb(b);
				}
			}
			v = u;
		}
	}
	
	for(int i = (int) 1e7; 1 <= i; --i)
		suf[i] += suf[i + 1];
	for(int i = (int) 1e7; 1 <= i; --i)
		suf[i] = max(suf[i], suf[i + 1]);	
		
		
	int L = 0;
	int R = 1e7 + 1;
	while(L < R) {
		int M = (L + R + 1) / 2;
		if(fun(M) == 1)
			L = M;
		else
			R = M - 1;
	}
	if(!L)
		printf("-1\n");
	else
		printf("%d\n", L);
	
	
	return 0;
}