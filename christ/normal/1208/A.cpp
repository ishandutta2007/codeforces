#include<bits/stdc++.h>
using namespace std;
char _;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template <typename t> void scan (t& x) {do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0);}
template <typename t, typename ...r> void scan (t& x, r&... xs) {scan(x); scan(xs...);}
const int MAXN = 1e5+2;
int main () {
	int t;
	scanf ("%d",&t);
	while (t--) {
		int a,b,n;
		scanf ("%d %d %d",&a,&b,&n);
		if (n%3 == 0) printf ("%d\n",a);
		else if (n%3==1) printf ("%d\n",b);
		else printf ("%d\n",a^b);
	}
	return 0;
}