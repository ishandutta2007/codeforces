#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(c) c.begin(),c.end()
#define INF int(1e9+7)

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int N = 1e5 + 87;

int ct[N];

int main()
{
	IO_OP;

	int n, m, c = 0;
	cin >> n >> m;
	string s = "";
	for(int i=0;i<m;i++) {
		int t;
		cin >> t;
		if(ct[t] == 0)  {
			c++;
		}
		// cout << "c: " << c << endl;
		ct[t]++;
		if(c == n) {
			for(int i=1;i<=n;i++) {
				ct[i]--;
				if(ct[i] == 0) {
					c--;
				}
			}
			s += '1';
		}
		else s += '0';
	}
	cout << s << endl;
}