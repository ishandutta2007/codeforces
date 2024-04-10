#include<bits/stdc++.h>
using namespace std;

int N,D;
vector<int> G[3005];
const int p=1000000007;

int F[3005][3005],S[3005][3005];
void DFS(int x){
	for(int i=1;i<=N+1;i++) F[x][i]=1;
	for(int i=0;i<G[x].size();i++){
		int y=G[x][i];
		DFS(y);
		for(int i=1;i<=N+1;i++) F[x][i]=1LL*F[x][i]*S[y][i]%p;
	}
	for(int i=1;i<=N+1;i++) S[x][i]=(S[x][i-1]+F[x][i])%p;
}

int inv[3005],ifac[3005];

int main(){
	scanf("%d%d",&N,&D);
	for(int i=2;i<=N;i++){
		int pi;scanf("%d",&pi);
		G[pi].push_back(i);
	}
	DFS(1);
	if(D<=N+1){printf("%d\n",S[1][D]);return 0;}
	ifac[0]=1;
	for(int i=1;i<=N+1;i++)
		inv[i]=(i==1)?1:1LL*(p-p/i)*inv[p%i]%p,
		ifac[i]=1LL*ifac[i-1]*inv[i]%p;
	int ans=0;
	for(int i=1;i<=N+1;i++){
		int tmp=1LL*S[1][i]*ifac[i-1]%p*ifac[N+1-i]%p;
		for(int j=1;j<=N+1;j++)if(j!=i)
			tmp=1LL*tmp*(D-j)%p;
		if((N+1-i)&1) tmp=p-tmp;
		ans=(ans+tmp)%p;
	}
	printf("%d\n",ans);
}