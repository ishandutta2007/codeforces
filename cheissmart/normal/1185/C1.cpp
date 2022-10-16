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

int t[105];

int main()
{
	IO_OP;
	
	int n, m;
	cin >> n >> m;
	for(int i=0;i<n;i++)
		cin >> t[i];
	for(int i=0;i<n;i++) {
		if(i == 0) {
			cout << 0 << " ";
			continue;
		}
		int r = m - t[i], s = 0, j;
		sort(t, t+i);
		for(j=0;j<i&&s<r;j++)
			s += t[j];
		if(s > r) s -= t[j-1], j--;
		cout << i - j << " ";
	}
	
}