#include <bits/stdc++.h>
#define rep(i,n) for(i=1;i<=(n);i++)
#define rep0(i,n) for(i=0;i<(n);i++)
using namespace std;
int n,m,q,ans,s[200005];
void solve(){
	int i,j;
	scanf("%d%d",&n,&m); 
	ans=0;rep(i,n)s[i]=0;
	rep(i,m){
		int x,y;scanf("%d%d",&x,&y);if(x>y)swap(x,y);
		if(++s[x]==1)ans++; 
	}
	scanf("%d",&q);
	while(q--){
		int op;scanf("%d",&op);
		if(op==3){
			printf("%d\n",n-ans);
		}
		if(op==1){
			int x,y;scanf("%d%d",&x,&y);if(x>y)swap(x,y);
			if(++s[x]==1)ans++; 
		}
		if(op==2){
			int x,y;scanf("%d%d",&x,&y);if(x>y)swap(x,y);
			if(--s[x]==0)ans--; 
		}
	}
}
int main(){
	int t;t=1;
	while(t--){
		solve();
	} 
	return 0;
}