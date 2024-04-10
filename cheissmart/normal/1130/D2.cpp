#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

vi G[5005];
int c[5005];

int main()
{
	IO_OP;
	
	int n, m;
	cin >> n >> m;
	for(int i=0;i<m;i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		G[a].PB(b);
	}
	for(int j=0;j<n;j++) {
		c[j] = INF;
		for(int k:G[j]) 
			c[j] = min(c[j],(k-j+n)%n);
	}
		
	for(int i=0;i<n;i++) {
		int mx = -INF;
		for(int j=0;j<n;j++) {
			if(G[j].size()) {
				mx = max(mx, (j-i+n)%n + (int)(G[j].size()-1)*n + c[j]);
			}
		}
		cout << mx << " ";
	}
}