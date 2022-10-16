#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define INF int(1e9+7)

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

bool a[128][128];

int main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			char c;
			cin >> c;
			a[i][j] = c == 'o';	
		}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			int ct = 0;
			ct += a[i+1][j];
			ct += a[i-1][j];
			ct += a[i][j+1];
			ct += a[i][j-1];
			if(ct & 1) {
				cout << "NO" << endl;
				return 0;
			}
		}
	}
	cout << "YES" << endl;
}