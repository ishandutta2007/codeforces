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

int a[300005][2];

int main()
{
	IO_OP;
	
	int n, m;
	cin >> n >> m;
	for(int i=0;i<m;i++) {
		cin >> a[i][0] >> a[i][1];
	}
	int s;
	for(s=1;s<m;s++) {
		if(a[s][0] != a[0][0] && a[s][1] != a[0][1] && a[s][0] != a[0][1] && a[s][1] != a[0][0])
			break;
	}
	if(s == m) {
		cout << "YES" << endl;
		return 0;
	}
	for(int i=0;i<2;i++) {
		for(int j=0;j<2;j++) {
			int x = a[0][i], y = a[s][j];
			if(x == y) continue;
			bool ok = 1;
			for(int k=0;k<m;k++)
				if(a[k][0] != x && a[k][1] != x && a[k][0] != y && a[k][1] != y)
					ok = 0;
			if(ok) {
				cout << "YES" << endl;
				return 0;
				
			}
		}
	}
	cout << "NO"<<endl;
}