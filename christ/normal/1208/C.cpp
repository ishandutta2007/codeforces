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
	int n;
	scanf ("%d",&n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf ("%d ",j/4*16 + i/4*16*(n/4) + (i%4)*4 + (j%4));
		}
		printf ("\n");
	}
	return 0;
}