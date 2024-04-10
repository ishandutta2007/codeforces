#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int MN = 2e5+2, MOD = 1e9+7, LOG = 15;
#define all(x) (x).begin(),(x).end()
void solve () {
	ll n;
	int cnt = 0;
	scanf ("%lld",&n);
	while (n%5==0) n = (n*4)/5, ++cnt;
	while (n%3==0) n = (n*2)/3, ++cnt;
	while (n%2==0) n /= 2, ++cnt;
	printf ("%d\n",n==1?cnt:-1); 
}
int main() {
	int t;
	scanf ("%d",&t);
	while (t--) solve();
    return 0;
}