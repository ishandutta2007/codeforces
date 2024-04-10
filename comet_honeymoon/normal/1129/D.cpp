#include<bits/stdc++.h>
using namespace std;

const int maxN=100005,LEN=170;
const int p=998244353;

int N,K,len;
int A[maxN],F[maxN],pre[maxN];int pos[maxN];
int inb[maxN];
int B[maxN];
int G[LEN][maxN<<1|1],lzy[LEN];
int ans;
void calc(int i,int w){
	if(B[i]+lzy[inb[i]]==K+1&&w==-1)
		ans=(ans+F[i])%p;
	if(B[i]+lzy[inb[i]]==K&&w==1)
		ans=(ans-F[i]+p)%p;
	G[inb[i]][B[i]+maxN]=(G[inb[i]][B[i]+maxN]-F[i]+p)%p;
	B[i]+=w;
	G[inb[i]][B[i]+maxN]=(G[inb[i]][B[i]+maxN]+F[i])%p;
}
void Update(int L,int R,int w){
	if(inb[L]==inb[R]){
		for(int i=L;i<=R;i++) calc(i,w);
		return;
	}
	for(int i=L;i<(inb[L]+1)*len;i++) calc(i,w);
	for(int i=inb[R]*len;i<=R;i++) calc(i,w);
	for(int i=inb[L]+1;i<inb[R];i++){
		if(w==1) ans=(ans-G[i][K-lzy[i]+maxN]+p)%p;
		if(w==-1) ans=(ans+G[i][K-lzy[i]+maxN+1])%p;
		lzy[i]+=w;
	}
}

int main(){
	scanf("%d%d",&N,&K);len=min(N,(int)(2*sqrt(N)));
	for(int i=1;i<=N;i++){
		scanf("%d",&A[i]),pre[i]=pos[A[i]],pos[A[i]]=i;
		inb[i]=i/len;
	}
	F[0]=1;G[0][maxN]=1;ans=1;
	for(int i=1;i<=N;i++){
		Update(pre[i],i-1,1);
		if(pre[i]) Update(pre[pre[i]],pre[i]-1,-1);
		F[i]=ans;G[inb[i]][maxN]=(G[inb[i]][maxN]+ans)%p;ans=(ans+ans)%p;
	}
	printf("%d\n",F[N]);
}