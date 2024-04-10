#include <bits/stdc++.h>
#define print(x) cerr << #x << " = " << x << endl;
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int s, n;
const int N = 1005;
int a[2][N];

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n >> s;
	--s;
	for(int j = 0; j < 2; ++j)
		for(int i = 0; i < n; ++i)
			cin >> a[j][i];

	if(a[0][0] == 0) {
		cout << "NO\n";
		return 0;
	}
	// whole way
	if(a[0][s] == 1) {
		cout << "YES\n";
		return 0;
	}
	//left then right
	for(int t = s; t < n; ++t) {
		if(a[1][s] == 1 && a[1][t] == 1 &&a[0][t] == 1) {
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
}