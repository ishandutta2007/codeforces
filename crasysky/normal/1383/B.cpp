#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define mp make_pair
#define fi first
#define se second
#define ll long long
using namespace std;
const int N=1e6+6; int c[30];
int main(){
	int T; scanf("%d",&T);
	while (T--){
	    int n; scanf("%d",&n);
	    rep(i,0,30) c[i]=0;
	    rep(i,1,n){
	    	int x; scanf("%d",&x);  
	    	rep(j,0,30) c[j]+=x>>j&1;
	    }
	    bool f=false;
		per(j,30,0)
			if (c[j]&1){//(x,y)=(x,y-2)
				puts((c[j]+1>>1&1)||(n-c[j])&1?"WIN":"LOSE");
				f=true; break;
			}
		if (!f) puts("DRAW");
	}
	return 0;
}