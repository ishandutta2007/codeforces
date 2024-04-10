#include<bits/stdc++.h>
using namespace std;

int N,P,Q;
int V[4005],W[4005]; 

vector<int> G[80005];
void Update(int x,int l,int r,int L,int R,int K){
	if(L<=l&&r<=R){G[x].push_back(K);return;}
	int mid=(l+r)>>1;
	if(L<=mid) Update(x<<1,l,mid,L,R,K);
	if(R>mid) Update(x<<1|1,mid+1,r,L,R,K);
	return;
}
int ANS[20005];
vector<int> QB[20005],Qid[20005];
int F[20][4005];
int ans[4005];
void Query(int x,int l,int r,int k){
	for(int i=0;i<G[x].size();i++){
		int v=V[G[x][i]],w=W[G[x][i]];
		for(int j=4000;j>=v;j--)
			F[k][j]=max(F[k][j],F[k][j-v]+w);
	}
	if(l==r){
		ans[0]=F[k][0];
		for(int j=1;j<=4000;j++) ans[j]=max(ans[j-1],F[k][j]);
		for(int i=0;i<QB[l].size();i++)
			ANS[Qid[l][i]]=ans[QB[l][i]];
		return;
	}
	int mid=(l+r)>>1;
	for(int j=0;j<=4000;j++) F[k+1][j]=F[k][j];
	Query(x<<1,l,mid,k+1);
	for(int j=0;j<=4000;j++) F[k+1][j]=F[k][j];
	Query(x<<1|1,mid+1,r,k+1);
}

int main(){
	scanf("%d%d",&N,&P);
	for(int i=1;i<=N;i++){
		int t;scanf("%d%d%d",&V[i],&W[i],&t);
		Update(1,1,20000,t,t+P-1,i);
	}
	scanf("%d",&Q);
	for(int i=1;i<=Q;i++){
		int a,b;scanf("%d%d",&a,&b);
		QB[a].push_back(b);Qid[a].push_back(i);
	}
	memset(F[0],192,sizeof(F[0]));F[0][0]=0;
	Query(1,1,20000,0);
	for(int i=1;i<=Q;i++) printf("%d\n",ANS[i]);
}