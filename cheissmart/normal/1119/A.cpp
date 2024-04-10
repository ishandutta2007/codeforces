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

int a[300005];

int main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> a[i];	
	int ans = 0;
	for(int i=1;i<n;i++)
		if(a[i] != a[0])
			ans = max(ans, i);
	for(int i=0;i<n-1;i++)
		if(a[i] != a[n-1])
			ans = max(ans, n - 1 - i);
	cout << ans << endl;
}