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

string a[500005];

int main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> a[i];
	for(int i=n-2;i>=0;i--) {
		if(a[i] > a[i+1]) {
			int j;
			for(j=0;j<min(a[i].size(), a[i+1].size());j++)
				if(a[i][j] > a[i+1][j]) break;
			a[i] = a[i].substr(0, j);
		}
	}
	for(int i=0;i<n;i++)
		cout << a[i] << endl;
}