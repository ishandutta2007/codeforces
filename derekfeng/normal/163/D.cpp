#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
int m;
ll ans,ansa,ansb,ansc,V;
ll num[22],pw[22][66];
int cnt[22];
void dfs2(int x,ll B,ll A,ll LFT){
	if(B>1e9||B*B>V/A||B*LFT<A)return;
	if(x==m){
		ll C=V/A/B;
		if(ans>A*B+A*C+B*C)ans=A*B+A*C+B*C,ansa=A,ansb=B,ansc=C;
		return;
	}
	LFT/=pw[x][cnt[x]];
	for(int i=cnt[x]/2+1;i<=cnt[x];i++){
		B*=pw[x][i],cnt[x]-=i;
		dfs2(x+1,B,A,LFT);
		B/=pw[x][i],cnt[x]+=i;
	}
	for(int i=cnt[x]/2;i>=0;i--){
		B*=pw[x][i],cnt[x]-=i;
		dfs2(x+1,B,A,LFT);
		B/=pw[x][i],cnt[x]+=i;
	}
	LFT*=pw[x][cnt[x]];
}
void dfs1(int x,ll A){
	if(A>1e6||A*A*A>V)return;
	if(x==m){
		if(ans<=(double)sqrt(V/A)*A*2.0+V/A)return;
		dfs2(0,1,A,V/A);
		return;
	}
	for(int i=cnt[x]/2+1;i<=cnt[x];i++){
		A*=pw[x][i],cnt[x]-=i;
		dfs1(x+1,A);
		A/=pw[x][i],cnt[x]+=i;
	}
	for(int i=cnt[x]/2;i>=0;i--){
		A*=pw[x][i],cnt[x]-=i;
		dfs1(x+1,A);
		A/=pw[x][i],cnt[x]+=i;
	}
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&m);V=1;
		for(int i=0;i<m;i++){
			scanf("%I64d%d",&num[i],&cnt[i]);pw[i][0]=1;
			for(int j=0;j<cnt[i];j++)V*=num[i],pw[i][j+1]=pw[i][j]*num[i];
		}
		ans=4e18;
		dfs1(0,1);
		printf("%I64d %I64d %I64d %I64d\n",ans*2,ansa,ansb,ansc);
	}
}