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

const int M = 998244353;
const int N=200005;
ll a[N],b[N];
int main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i=0;i<n;i++) {
		cin >> a[i];
		a[i] *= (i+1ll)*(n-i);
	}
	sort(a,a+n);
	for(int i=0;i<n;i++)
		cin >> b[i];
	sort(b,b+n);
	ll ans = 0;
	for(int i=0;i<n;i++)
		ans += a[i] % M * b[n-1-i]%M;
	cout << ans % M <<endl;
}