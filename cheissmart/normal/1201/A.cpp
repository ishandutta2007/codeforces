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

int a[5][1024];

int main()
{
	IO_OP;
	
	int n, m;
	cin >> n >> m;
	for(int i=0;i<n;i++) {
		string s;
		cin >> s;
		for(int j=0;j<m;j++)
			a[s[j]-'A'][j]++;
	}
	int ans = 0;
	for(int i=0;i<m;i++) {
		int p;
		cin >> p;
		int mx = -1;
		for(int j=0;j<5;j++)
			mx = max(mx, a[j][i]);
		ans += mx * p;
	}
	cout << ans << endl;

}