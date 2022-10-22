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

const int nax = 2e5 + 111;

int ile[4];
int n;
char s[nax];
 
map <char, int> mapka; 

int prz[4];
 
int main() {
	scanf("%d %s", &n, s);
	mapka['R'] = 1;
	mapka['L'] = 0;
	mapka['U'] = 2;
	mapka['D'] = 3;
	
	prz[0] = 1;
	prz[1] = 0;
	prz[2] = 3;
	prz[3] = 2;
	
	int ans = 0;
	FOR(i, 0, n - 1) {
		int c = mapka[s[i]];
		if(ile[prz[c]]) {
			ans += 1;
			FOR(j, 0, 3)
				ile[j] = 0;
			ile[c] += 1;
		}
		else {
			ile[c] += 1;
		}
	}
	printf("%d", ans + 1);
		
	
	
	
	
	return 0;
}