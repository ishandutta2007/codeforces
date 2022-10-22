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

int n, m, a[nax];
int ile[nax];
int id[nax];
int fre;
int l[nax], r[nax], ans[nax];
int pref[nax];

int main() {
	scanf("%d %d", &n, &m);
	FOR(i, 1, n) {
		scanf("%d", &a[i]);
		if(a[i] < nax)
			ile[a[i]] += 1;
	}
	FOR(i, 1, m) {
		scanf("%d %d", &l[i], &r[i]);
	}
	FOR(i, 1, nax - 1) {
		if(ile[i] >= i) {
			FOR(j, 1, n) {
				pref[j] = 0;
				pref[j] = pref[j - 1] + (a[j] == i);
			}
			FOR(j, 1, m) {
				int ile = pref[r[j]] - pref[l[j] - 1];
				if(ile == i)
					ans[j] += 1;
			}
		}
	}
	FOR(i, 1, m)
		printf("%d\n", ans[i]);
				
			
		
		
		
	
	
	
	
	return 0;
}