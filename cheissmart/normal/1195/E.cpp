#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define int ll

using namespace std;

typedef long long ll;

const int INF = 1e9 + 7, N = 12;

int a[3003][3003], b[3003][3003];

int32_t main()
{
	IO_OP;
	
	int n, m, aa, bb, x, y, z;
	cin >> n >> m >> aa >> bb;
	cin >> a[0][0] >> x >> y >> z;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(i || j) {
				if(j)
					a[i][j] = (a[i][j-1] * x + y) % z;
				else
					a[i][j] = (a[i-1][m-1] * x + y) % z;
	
			}
	for(int i=0;i<n;i++) {
		deque<int> dk;
		for(int j=m-1;j>=0;j--) {
			while(dk.size() && a[i][j] <= a[i][dk.front()])
				dk.pop_front();
			dk.push_front(j);
			while(dk.size() && dk.back() >= j+bb)
				dk.pop_back();
			b[i][j] = a[i][dk.back()];
		}
	}
		for(int j=0;j<m;j++) {
			deque<int> dk;
			for(int i=n-1;i>=0;i--) {
			while(dk.size() && b[i][j] <= b[dk.front()][j])
				dk.pop_front();
			dk.push_front(i);
			while(dk.size() && dk.back() >= i+aa)
				dk.pop_back();
			a[i][j] = b[dk.back()][j];
		}
	}
	int ans = 0;
	for(int i=0;i+aa-1<n;i++) {
		for(int j=0;j+bb-1<m;j++) {
			ans += a[i][j];
		}
	}
	cout << ans << endl;
}