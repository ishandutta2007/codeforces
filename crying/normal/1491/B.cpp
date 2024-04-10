#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
#define next Cry_For_theMoon
#define il inline
typedef long long ll;
using namespace std;
const int MAXN=110,INF=2e9+10;
int T,n,u,v,a[MAXN],ans;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&u,&v);
		ans=INF;
		rep(i,1,n){
			scanf("%d",&a[i]);
		}
		rep(i,1,n-1){
			//ii+1
			if(abs(a[i]-a[i+1])>=2){
				ans=0;break;
			}
			if(a[i]!=a[i+1]){
				ans=min(ans,v);
				ans=min(ans,u);
			}else{
				if(i!=1 && a[i-1]!=a[i])ans=min(ans,u);
				if(i+1!=n && a[i+2]!=a[i+1])ans=min(ans,u);
				ans=min(ans,u+v);
				ans=min(ans,v+v); 
			}
		}
		printf("%d\n",ans);
	}
	
	return 0;
}