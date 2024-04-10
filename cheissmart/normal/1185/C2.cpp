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

int t[200005], c[105];

int main()
{
	IO_OP;
	
	int s = 0;
	int n, m;
	cin >> n >> m;
	for(int i=0;i<n;i++)
		cin >> t[i];
	for(int i=0;i<n;i++) {
		int r = m - t[i], ss = 0, b = 0;
		for(int i=1;i<=100;i++) {
			if(ss + c[i] * i <= r) ss += c[i] * i, b += c[i];
			else {
				int x = (r - ss) / i;
				b += x;
				break;
			}
		}
		cout << i - b << " ";
		s += t[i];
		c[t[i]]++;
	}
}