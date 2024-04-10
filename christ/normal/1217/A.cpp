#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
const int MN = 5e5+3, MOD = 1e9+7;
int main() {
	int t;
	scanf ("%d",&t);
	while (t--) {
		int a,b,c;
		scanf ("%d %d %d",&a,&b,&c);
		int mn = max(0,min(c+1,(b+c-a+2)/2));
		printf ("%d\n",max(0,c-mn+1));
	}
    return 0;
}