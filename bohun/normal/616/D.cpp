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
#define bignum vector <int>
 
 
using namespace std;

const int nax = 1e6 + 111; 

int n, k;
int a[nax];
int ile[nax];
int mam = 0;
int best = 0;
int l, r;
	

int main() {
	scanf("%d%d", &n, &k);
	FOR(i, 1, n)
		scanf("%d", &a[i]);
	int j = 1;
	FOR(i, 1, n) {
		while(j <= n && (mam < k || ile[a[j]] > 0)) {
			ile[a[j]] += 1;
			if(ile[a[j]] == 1)
				mam += 1;
			j += 1;
		}
		if(mam <= k) {
			if(best < j - i) {
				best = j - i;
				l = i;
				r = j - 1;
			}
		}
		ile[a[i]] -= 1;
		if(!ile[a[i]])
			mam -= 1;
	}
	printf("%d %d", l, r);
	
		
	
	
	return 0;
}