#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
const int MN = 1e5 + 5, MOD = 1e9 + 7;
int main () {
	int b,g,n;
	scanf ("%d %d %d",&b,&g,&n);
	int low = max(0,n-g), high = min(n,b);
	printf ("%d\n",high - low + 1);
	return 0;
}