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

int a[100005];

int main()
{
	IO_OP;
	
	int n, x, y;
	cin >> n >> x >> y;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	for(int i=1;i<=n;i++) {
		int mn = INF;
		for(int j=i-1;j>=i-x && j > 0;j--)
			mn = min(mn, a[j]);
		for(int j=i+1;j<=i+y && j<=n;j++)
			mn = min(mn, a[j]);
		if(mn > a[i]) {
			cout << i << endl;
			return 0;
		}
	}

}