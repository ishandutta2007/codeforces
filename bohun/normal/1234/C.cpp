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

const int mod = 1e9 + 7;
const int nax = 2e5 + 111;

int q;
int n;
string s[2];
int t[2][nax];
bool ri[2][nax], up[2][nax];

int main() {
	ios;
	cin >> q;
	while(q--) {
		cin >> n;
		cin >> s[0] >> s[1];
		s[0] = '#' + s[0];
		s[1] = '#' + s[1];
		FOR(i, 1, n) {
			if(s[0][i] <= '2')
				t[0][i] = 0;
			else
				t[0][i] = 1;
			if(s[1][i] <= '2')
				t[1][i] = 0;
			else
				t[1][i] = 1;
		}
		
		
		FOR(i, 0, n + 1)
			FOR(j, 0, 1) {
				ri[j][i] = up[j][i] = 0;
			}
		ri[0][1] = 1;
		
		FOR(i, 1, n) {
			FOR(j, 0, 1) {
				if(ri[j][i]) {
					if(t[j][i] == 0)
						ri[j][i + 1] = 1;
					if(t[j][i] == 1)
						up[!j][i] = 1;
				}
				if(up[j][i]) {
					if(t[j][i] == 1)
						ri[j][i + 1] = 1;
				}
			}
			FOR(j, 0, 1) {
				if(ri[j][i]) {
					if(t[j][i] == 0)
						ri[j][i + 1] = 1;
					if(t[j][i] == 1)
						up[!j][i] = 1;
				}
				if(up[j][i]) {
					if(t[j][i] == 1)
						ri[j][i + 1] = 1;
				}
			}
		}
		if(ri[1][n + 1]) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
		
	
	
	return 0;
}