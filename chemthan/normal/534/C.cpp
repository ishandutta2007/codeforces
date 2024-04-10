#include <iostream>
using namespace std;

#define FOR(i, n) for(int i = 0; i < n; i++)
#define FOR2(i, a, b) for(int i = a; i < b; i++)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) > (b) ? (b) : (a))
typedef long long ll;

int n;
ll a;
int d[200000];

void solve()
{
	//freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	ll s = 0;
	cin>>n>>a;
	FOR(i, n) {cin>>d[i]; s += d[i];}
	FOR(i, n){
		int k = 0;
		if (a + d[i] - s - 1 > 0) k += MIN(a + d[i] - s - 1, d[i]);
		if (a - n + 2 > 0 && a - n + 2 <= d[i]) k += d[i] - a + n - 1;
		cout<<k<<" ";
	}
}

int main()
{
	solve();
	return 0;
}