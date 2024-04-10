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

char a[512][512];

int main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			cin >> a[i][j];
		}
	}
	if(n < 3) {
		cout << 0 << endl;
		return 0;
	}
	int ans = 0;
	for(int i=1;i<n-1;i++) {
		for(int j=1;j<n-1;j++) {
			if(a[i][j] == 'X' && a[i+1][j+1] == 'X' && a[i+1][j-1] == 'X' &&
			   a[i-1][j-1] == 'X' && a[i-1][j+1] == 'X') {
				ans++;
			   }
			   
		}
	}
	cout << ans << endl;
}