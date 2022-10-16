#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define endl '\n'
#define debug(x) cerr << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

int a[4][4] = {
	{8, 9, 1, 13},
	{3, 12, 7, 5},
	{0, 2, 4, 11},
	{6, 10, 15, 14}
}, b[1024][1024];

int32_t main()
{
	IO_OP;
	int n;
	cin >> n;
	int k = n / 4;
	for(int i=0;i<4;i++) {
		for(int j=0;j<4;j++) {
			int r = i * k, c = j * k;
			for(int x=r;x<r+k;x++) {
				for(int y=c;y<c+k;y++) {
					b[x][y] = ((x-r + (y-c)*k) << 4) + a[i][j];
				}
			}
		}
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cout << b[i][j] << " \n"[j==n-1];
	
}