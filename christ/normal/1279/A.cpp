#include<bits/stdc++.h>
using namespace std;
const int MN = 81, LOG = 60, MOD = 1e9+7, ADD = MN*MN*2;
using pii = pair<int,int>;
using ll = long long;
int main () {
	int t;
	scanf ("%d",&t);
	while (t--) {
		int a,b,c;
		scanf ("%d %d %d",&a,&b,&c);
		ll n = ((ll)a+b+c+1)/2;
		if (a > n || b > n || c > n) printf ("No\n");
		else printf ("Yes\n");
	}
	return 0;
}