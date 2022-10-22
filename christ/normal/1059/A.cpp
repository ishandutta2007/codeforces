#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int MN = 2e5+2, MOD = 1e9+9, BASE = 31, INF = 1e9, ED = 1e3+1;
#define all(x) (x).begin(),(x).end()
int main() {
	int n,L,a;
	scanf ("%d %d %d",&n,&L,&a);
	int laste = 0, ret = 0;
	for (int i = 1; i <= n; i++) {
		int t,l;
		scanf ("%d %d",&t,&l);
		ret += (t-laste)/a;
		laste = t+l;
	}
	ret += (L-laste)/a;
	printf ("%d\n",ret);
    return 0;
}