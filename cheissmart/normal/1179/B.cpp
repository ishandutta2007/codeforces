#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

int main()
{
	IO_OP;
	int n, m;
	cin >> n >> m;
	for(int l=1,r=m;l<=r;l++,r--)  {
		if(l < r) {
			int x = 1, y = n;
			for(int i=0;i<n;i++) {
				cout << x << " " << l << endl;
				cout << y << " " << r << endl;
				x++, y--;
			}
		} else {
			int x = 1, y = n;
			for(int i=0;i<n;i++) {
				if(i % 2 == 0) cout << x++ << " " << l << endl;
				else cout << y-- << " " << r << endl;
			}
		}
	}
	
}