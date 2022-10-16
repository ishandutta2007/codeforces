#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define INF int(1e9+7)
#define int long long
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
const int N = 1000010, M = 998244353;
int inv[N];
int32_t main()
{
//	IO_OP;
	
	int n;
	cin >> n;
	int f = 1;
	inv[0] = inv[1] = 1;
	for(int i=2;i<=n;i++) {
		f *= i;
		f %= 998244353;
		inv[i] = (M - M/i) * inv[M%i] % M;
	}
	int s = 0, cs = 1;
	for(int i=1;i<n;i++) {
		cs = cs * inv[i] % M;
		s += f * cs % M;
	}
	cout << (n*f%998244353 - s%M+998244353) % 998244353 << endl; 
}