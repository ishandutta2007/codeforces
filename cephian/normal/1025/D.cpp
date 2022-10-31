#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define fio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef unsigned long long ll;

const int N = 705;
bool dpl[N][N];
bool dpr[N][N];

bool ok[N][N];
int A[N];

int gcd(int a, int b) {
	if(b) return gcd(b, a%b);
	return a;
}

int main() {
	fio;
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> A[i];
	
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j) {
			ok[i][j] = gcd(A[i], A[j]) > 1;
		}

	for(int i = 0; i <= n; ++i)
		for(int j = 0; j <= n; ++j)
			dpl[i][j] = dpr[i][j] = true;

	for(int len = 2; len <= n; ++len) {
		for(int i = 1; i+len-1 <= n; ++i) {
			int j = i+len-1;
			// do left
			dpl[i][j] = false;
			for(int k = i; k < j; ++k) {
				if(ok[k][j] && dpl[i][k] && dpr[k][j-1]) {
					dpl[i][j] = true;
					break;
				}
			}
			// do right
			dpr[i][j] = false;
			for(int k = i+1; k <= j; ++k) {
				if(ok[k][i] && dpr[k][j] && dpl[i+1][k]) {
					dpr[i][j] = true;
					break;
				}
			}
		}
	}
	// lets go boy
	for(int k = 1; k <= n; ++k) {
		if(dpl[1][k] && dpr[k][n]) {
			cout << "Yes\n";
			return 0;
		}
	}
	cout << "No\n";
}