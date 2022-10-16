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

int s[55], a[55][10004], vis[10004];

int main()
{
	IO_OP;
	
	int m, n;
	cin >> m >> n;
	for(int i=0;i<m;i++) {
		cin >> s[i];
		for(int j=0;j<s[i];j++)
			cin >> a[i][j];
	}
	for(int i=0;i<m;i++)
		for(int j=0;j<i;j++) {
			for(int k=1;k<=n;k++)
				vis[k] = 0;
			for(int k=0;k<s[i];k++)
				vis[a[i][k]] = 1;
			bool ok = 0;
			for(int k=0;k<s[j];k++)
				if(vis[a[j][k]]) ok = 1;
			if(!ok) {
				cout << "impossible" << endl;
				return 0;
			}
		}
	
	cout << "possible" << endl;
}