#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
typedef long long int LLI;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
#define MOD 998244353

int index(char c) {
	if ((c >= 'a') && (c <= 'z')) return c-'a';
	else if ((c >= 'A') && (c <= 'Z')) return c-'A'+26;
	else return c-'0'+52;
}
vector<string> v[8][62][62];
int arr[62][62],num[62][62][62];
int main() {
	int i;
	int n;
	string s;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> s;
		int a = index(s[0]),b = index(s.back());
		v[s.size()-3][a][b].pb(s);
		reverse(s.begin(),s.end());
		v[s.size()-3][b][a].pb(s);
	}
	
	int j,k,l,m;
	LLI ans = 0;
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 62; j++) {
			for (k = 0; k < 62; k++) {
				sort(v[i][j][k].begin(),v[i][j][k].end());
				v[i][j][k].resize(unique(v[i][j][k].begin(),v[i][j][k].end())-v[i][j][k].begin());
				arr[j][k] = v[i][j][k].size();
			}
		}
		for (j = 0; j < 62; j++) {
			for (k = j; k < 62; k++) {
				for (l = k; l < 62; l++) {
					num[j][k][l] = 0;
					for (m = 0; m < 62; m++) num[j][k][l] += ((((LLI) arr[j][m]*arr[k][m]) % MOD)*arr[l][m]) % MOD,num[j][k][l] %= MOD;
				}
			}
		}
		for (j = 0; j < 62; j++) {
			for (k = j; k < 62; k++) {
				for (l = k; l < 62; l++) {
					for (m = l; m < 62; m++) {
						LLI x = ((((LLI) num[j][k][l]*num[j][k][m]) % MOD)*(((LLI) num[j][l][m]*num[k][l][m]) % MOD)) % MOD;
						int w = 24;
						if ((j == k) && (k == l) && (l == m)) w /= 24;
						else if ((j == k) && (k == l)) w /= 6;
						else if (j == k) w /= 2;
						if (j != k) {
							if ((k == l) && (l == m)) w /= 6;
							else if (k == l) w /= 2;
						}
						if (k != l) {
							if (l == m) w /= 2;
						}
						ans += w*x,ans %= MOD;
					}
				}
			}
		}
	}
	printf("%lld\n",ans);
	
	return 0;
}