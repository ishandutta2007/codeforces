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
	int n,l,r;
	scanf ("%d %d %d",&n,&l,&r);
	int low = n-l+1, high = 1;
	int cur = 1;
	for (int i = 1; i < l; i++) {
		cur <<= 1;
		low += cur;
	}
	cur = 1;
	for (int i = 1; i < r; i++) {
		cur <<= 1;
		high += cur;
	}
	high += cur * (n-r);
	printf ("%d %d\n",low,high);
	return 0;
}