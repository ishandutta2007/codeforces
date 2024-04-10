#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
using namespace std;
const int N=1e6+6; int a[N],v[N];
int main(){
	int T; scanf("%d",&T);
	while (T--){
		int n,k; scanf("%d%d",&n,&k);
		rep(i,1,2*k) v[i]=0;
		rep(i,1,n) scanf("%d",&a[i]);
		rep(i,1,n/2){
			int x=a[i],y=a[n-i+1];
			if (x>y) swap(x,y);
			v[1]+=2,v[1+x]-=1;
			v[x+y]-=1,v[x+y+1]+=1;
			v[y+k+1]+=1;
		}
		rep(i,1,2*k) v[i]+=v[i-1];
		int ans=v[1]; rep(i,2,2*k) ans=min(ans,v[i]);
		printf("%d\n",ans);
	}
	return 0;
}