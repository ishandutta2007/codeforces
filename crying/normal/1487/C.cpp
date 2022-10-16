#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
using namespace std;
typedef long long ll;
const int MAXN=110;
int T,n,a,b,rest1[MAXN],rest2[MAXN],vis[MAXN][MAXN];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(ll t=0;t<=n*(n-1);t++){
			int v=n-1-t;
			if(v&1)continue;
			v/=2;
			//vt
			if(v>=n*(n-1)/2)continue;
			if(v+t>=n)continue;
			rep(i,1,n){
				rest1[i]=v;rest2[i]=t;
			}
			memset(vis,0,sizeof vis);
			rep(i,1,n){
				rep(j,1,n){
					if(i==j)continue;
					if(vis[i][j])continue;
					if(rest1[i]){
						rest1[i]--;
						vis[i][j]=1;
						vis[j][i]=3;
					}else if(rest2[i] && rest2[j]){
						rest2[i]--;
						rest2[j]--;
						vis[i][j]=vis[j][i]=2;
					}
				}
			}
			rep(i,1,n){
				if(rest1[i] || rest2[i])goto END;
				rep(j,1,n){
					if(i==j)continue;
					if(!vis[i][j])goto END;
				} 
			}
			rep(i,1,n){
				rep(j,i+1,n){
					if(vis[i][j]==1)printf("1 ");
					else if(vis[i][j]==2)printf("0 ");
					else printf("-1 ");
				}
			}
			printf("\n");
			break;
			END:continue;
		} 
	}
	
	return 0;
}