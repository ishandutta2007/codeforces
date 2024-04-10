#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
struct __test {} test;
using namespace std;
template <typename T>const __test &operator<<(const __test& d,
const T& v) {return cerr << "\033[31m" << v << "\033[0m",d;}
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

int g[55][55];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			cin >> g[i][j];
		}
	}
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			bool ok = false;
			for(int k = 0; !ok && k < n; ++k) {
				for(int l = 0; !ok && l < n; ++l) {
					if(g[i][j] == 1 || g[i][j]==g[i][k] + g[l][j])
						ok = true;
				}
			}
			if(!ok) {
				cout << "No\n";
				return 0;
			}
		}
	}
	cout << "Yes\n";
}