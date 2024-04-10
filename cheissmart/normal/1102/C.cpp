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

int a[128];

int main()
{
	IO_OP;
	
	int n, x, y;
	cin >> n >> x >> y;
	for(int i=0;i<n;i++)
		cin >> a[i]; 
	if(x > y) {
		cout << n << endl;
		return 0; 
	}
	int ct = 0;
	for(int i=0;i<n;i++)
		if(a[i] <= x)
			ct++;
	cout << (ct + 1) / 2 << endl; 
}