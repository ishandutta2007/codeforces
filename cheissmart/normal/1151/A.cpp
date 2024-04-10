#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

int main()
{
	IO_OP;
	
	int n, ans = INF;
	string s, g = "ACTG";
	cin >> n >> s;
	for(int i=0;i<n-3;i++) {
		string r = s.substr(i, 4);
		int cans = 0;
		for(int j=0;j<4;j++) {
			int d = abs(r[j] - g[j]);
			cans += min(d, 26 - d);
		}
		ans = min(ans, cans);
	}
	cout << ans << endl;
	
}