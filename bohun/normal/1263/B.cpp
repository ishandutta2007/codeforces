#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, n) for(int i = 1; i <= n; ++i)
#define fi first
#define se second
#define cat(x) cout << #x << " = " << x << endl

using namespace std;

int T;
int n;
char s[15][6];
char r[15][6];

map <string, int> ok;
int pp[15];
 
int main() {
	scanf("%d", &T);
	while(T--) {
		map <string, int> ok;
		int ans = 0;
		scanf("%d", &n);
		for(int i = 1; i <= n; ++i) {
			pp[i] = 0;
			scanf("%s", s[i]);
			string x = "";
			for(int j = 0; j < 4; ++j)
				x.pb(s[i][j]);
			pp[i] = ok.find(x) == ok.end();
			ok[x] = 1;
		}
		for(int i = 1; i <= n; ++i) {
			string x = "";
			for(int j = 0; j < 4; ++j)
				x.pb(s[i][j]);
			if(pp[i] == 0) {
				ans += 1;
				bool ez = 0;
				for(int j = 0; j < 4; ++j) {
					for(int c = 0; c < 10; ++c) {
						if(ez) break;
						char pop = x[j];
						x[j] = (char) '0' + c;
						if(ok.find(x) == ok.end()) {
							ez = 1;
						}
						else {
							x[j] = pop;
						}
					}
				}
				for(int j = 0; j < 4; ++j)
					r[i][j] = x[j];
			}
			else {
				for(int j = 0; j < 4; ++j)
					r[i][j] = s[i][j];
			}
			ok[x] = 1;
		}
		printf("%d\n", ans);
		for(int i = 1; i <= n; ++i) {
			int k = 0;
			for(int j = 0; j < 4; ++j)
				k += r[i][j] != s[i][j];
			assert(k <= 1);
			
			for(int j = 0; j < 4; ++j)
				printf("%c", r[i][j]);
			printf("\n");
		}
	}

	
	
	
	
	return 0;
}