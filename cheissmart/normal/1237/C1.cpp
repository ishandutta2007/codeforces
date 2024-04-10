#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

bool vis[2048];
int x[2048], y[2048], z[2048];
int d(int i, int j) {
	return abs(x[i]-x[j]) + abs(y[i]-y[j]) + abs(z[i]-z[j]);
}

int32_t main()
{
	IO_OP;
	
	int n, i=0;
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> x[i] >> y[i] >> z[i];
	for(int _i=0;_i<n/2;_i++) {
		while(vis[i]) i++;
		vis[i] = 1;
		int k, mn = INF;
		for(int j=0;j<n;j++) {
			if(vis[j]) continue;
			if(d(i, j) < mn) {
				mn = d(i, j);
				k = j;
			}
		}
		vis[k] = 1;
		cout << i+1 << " " << k+1 << endl;
	}	
	
}