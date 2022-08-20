#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define vi vector<int>
 
#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define f first
#define s second
 
const int MOD = 1000000007;
const int MAX = 10000005;

string digits;
int n, strings[5000][5000], nxt[5000][5000], prefix[5000][5000];

int main() {
	cin >> n >> digits;
	for (int j = n-1; j > 0; --j) {
		for (int i = j-1; i >= 0; --i) {
			if (digits[i] != digits[j]) {
				nxt[i][j] = 0;
			} else {
				if (j == n-1) nxt[i][j] = 1;
				else nxt[i][j] = nxt[i+1][j+1]+1;
			}
		}
	}
	
	FOR(i,1,n+1) {
		strings[0][i] = 1;
		prefix[0][i] ++;
	}
	
	FOR(i,1,n) {
		FOR(j,i+1,n+1) {
			if (digits[i] == '0') {
				prefix[i][j] = prefix[i-1][j];
				continue;
			} else {
				if (2*i-j < 0) {
					strings[i][j] = prefix[i-1][i];
					prefix[i][j] = (prefix[i-1][j]+strings[i][j]) % MOD;
				} else {
					strings[i][j] = (prefix[i-1][i]+(MOD-prefix[2*i-j][i])) % MOD;
					if (nxt[2*i-j][i]<(j-i) && digits[2*i-j+nxt[2*i-j][i]] < digits[i+nxt[2*i-j][i]]) strings[i][j] = (strings[i][j]+strings[2*i-j][i]) % MOD;
					prefix[i][j] = (prefix[i-1][j]+strings[i][j]) % MOD;
				}
			}
		}
	}
	cout << prefix[n-1][n];
	return 0;
}