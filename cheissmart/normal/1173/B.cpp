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

int a[1005][1005];

int main()
{
	IO_OP;
	
	int n, i;
	cin >> n;
	int m = (n + 2) / 2;
	cout << m << endl;
	for(i=1;i<=n/2;i++)
		cout << "1 " << i << endl;
	for(;i<=n;i++)
		cout << m << " " << i-n/2 << endl;
	
}