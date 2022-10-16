#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define INF int(1e9+7)

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

int a[100];

int main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++) {
			int t;
			cin >> t;
			a[i] = max(a[i], t);
		}
	for(int i=0;i<n;i++)
		if(a[i] == n-1) {
			a[i] = n;
			break;
		}
	for(int i=0;i<n;i++)
		cout << a[i] << " ";
}