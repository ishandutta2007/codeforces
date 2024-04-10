#include<bits/stdc++.h>
#define ll long long
using namespace std;

int N,C;
int P[10005],S[10005];
ll F[2][10005];

int main(){
	scanf("%d%d",&N,&C);
	for(int i=1;i<=N;i++) scanf("%d",&P[i]);
	for(int i=1;i<=N;i++) scanf("%d",&S[i]);
	memset(F,0x3f,sizeof(F));
	F[0][0]=0;
	for(int i=1;i<=N;i++){
		F[1][0]=F[0][0]+P[i];
		for(int j=1;j<=i;j++)
			F[1][j]=min(F[0][j]+P[i]+1LL*C*j,F[0][j-1]+S[i]);
		swap(F[0],F[1]);
	}
	ll ans=0x3f3f3f3f3f3f3f3fLL;
	for(int j=0;j<=N;j++) ans=min(ans,F[0][j]);
	printf("%lld\n",ans);
}