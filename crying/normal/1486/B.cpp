#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
#define next Cry_For_theMoon
typedef long long ll;
using namespace std;
const int MAXN=1010,INF=2e9;
int T,n,x[MAXN],y[MAXN];
int bx[MAXN],by[MAXN],tot1,tot2;
ll ans;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);tot1=tot2=ans=0;
		rep(i,1,n){
			scanf("%d%d",&x[i],&y[i]);
			bx[tot1++]=x[i];by[tot2++]=y[i];
		} 
		sort(bx,bx+tot1);sort(by,by+tot2);
		ll xsz=bx[tot1/2]-bx[(tot1-1)/2]+1;
		ll ysz=by[tot2/2]-by[(tot2-1)/2]+1;
		printf("%lld\n",xsz*ysz);
	}
	
	return 0;
}