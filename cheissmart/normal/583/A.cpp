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

bool ok[55], ko[55];

int main()
{
	IO_OP;
	
	int n, ct = 0;
	cin >> n;
	for(int i=0;i<n;i++)
		for(int j=1;j<=n;j++) {
			int h, v;
			cin >> h >> v;
			if(!ok[h] && !ko[v]) {
				cout << i*n+j << " ";
				ok[h] = ko[v] = 1;
			}
		}
	
}