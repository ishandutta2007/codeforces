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

int a[102], b[102], c[102][102], h[102][102];

int main()
{
	IO_OP;
	
	int n, m, hh;
	cin >> n >> m >> hh;
	for(int i=0;i<m;i++)
		cin >> a[i];
	for(int i=0;i<n;i++)
		cin >> b[i];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin >> c[i][j];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++) {
			if(c[i][j]) {
				h[i][j] = min(a[j], b[i]);
			}
		}
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cout << h[i][j] << " \n"[j == m-1];
}