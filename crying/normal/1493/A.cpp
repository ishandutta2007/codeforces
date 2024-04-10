#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
#define next Cry_For_theMoon
#define il inline
typedef long long ll;
using namespace std;
const int MAXN=1010;
int T,n,k,ans,vis[MAXN];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		ans=0;memset(vis,0,sizeof vis);
		rep(i,k+1,n){
			vis[i]=1,ans++;
		}
		per(i,k-1,1){
			if(!vis[k-i]){
				vis[i]=1;
				ans++;
			}
		}
		printf("%d\n",ans);
		rep(i,1,n){
			if(vis[i]){
				printf("%d ",i);
			}
		}
		printf("\n");
	}
	return 0;
}