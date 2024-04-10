#include<stdio.h>
#define R register int
#define I inline
#define N 200001
#define M 400001
int Last[N],Next[M],End[M],ct,dp[N],col[N],ans[N];
I void Link(int &x,int &y){
	ct++;
	End[ct]=y;
	Next[ct]=Last[x];
	Last[x]=ct;
}
I void DFS(int x,int F){
	if(col[x]==0){
		dp[x]=-1;
	}else{
		dp[x]=1;
	}
	for(R i=Last[x];i!=0;i=Next[i]){
		if(End[i]!=F){
			DFS(End[i],x);
			if(dp[End[i]]>0){
				dp[x]+=dp[End[i]];
			}
		}
	}
}
I void DP(int x,int F){
	int ret=0;
	if(dp[x]>0){
		ret=dp[x];
		dp[F]-=ret;
	}
	if(dp[F]>0){
		dp[x]+=dp[F];
	}
	ans[x]=dp[x];
	for(R i=Last[x];i!=0;i=Next[i]){
		if(End[i]!=F){
			DP(End[i],x);
		}
	}
	dp[F]+=ret;
}
int main(){
	int n,x,y;
	scanf("%d",&n);
	for(R i=1;i<=n;i++){
		scanf("%d",col+i);
	}
	for(R i=1;i!=n;i++){
		scanf("%d%d",&x,&y);
		Link(x,y);
		Link(y,x);
	}
	DFS(1,0);
	printf("%d",dp[1]);
	for(R i=Last[1];i!=0;i=Next[i]){
		DP(End[i],1);
	}
	for(R i=2;i<=n;i++){
		printf(" %d",ans[i]);
	}
	return 0;
}