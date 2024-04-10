#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {	
	int T;
	scanf("%d",&T);
	while(T--) {
		int a,b;
		scanf("%d%d",&a,&b);
		ll ab = 1LL * a * b, lo = 0, hi = 1e6;
		while(lo < hi-1) {
			ll md = (lo+hi)/2;
			if(md * md * md >= ab) hi = md;
			else lo = md;
		}
		if(hi * hi * hi != ab || a % hi != 0 || b % hi != 0) printf("No\n");
		else printf("Yes\n");
	}
}