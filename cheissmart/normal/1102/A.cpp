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

int main()
{
	IO_OP;
	
	int n;
	cin >> n;
	ll s = 1LL*n*(n+1)/2;
	if(s & 1) cout << 1 << endl;
	else cout << 0 << endl;
}