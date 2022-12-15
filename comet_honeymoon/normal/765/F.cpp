#include<bits/stdc++.h>
using namespace std;

const int maxN=100005,LEN=350;
int N,len,M;
int inb[maxN];int beg[LEN];
int A[maxN],sA[maxN],As[maxN];
bool cmp(int a,int b){return A[a]<A[b];}
void inline mymin(int &a,int b){
	if(b<a) a=b;
}

int F[maxN][LEN];
int G[LEN][LEN];

vector<int> f,g;
int Merge(){
	int ans=0x3f3f3f3f;
	for(int i=1;i<f.size();i++) mymin(ans,abs(f[i-1]-f[i]));
	for(int i=1;i<g.size();i++) mymin(ans,abs(g[i-1]-g[i]));
	int i=0,j=0;
	while(i<f.size()&&j<g.size()){
		mymin(ans,abs(f[i]-g[j]));
		if(f[i]<g[j]) i++;else j++;
	}
	return ans;
}

int main(){
	scanf("%d",&N);len=sqrt(N);
	for(int i=1;i<=N;i++){
		scanf("%d",&A[i]);sA[i]=A[i];As[i]=i;
		inb[i]=(i-1)/len+1;
		if(!beg[inb[i]]) beg[inb[i]]=i;
	}
	inb[N+1]=inb[N]+1;beg[inb[N]+1]=N+1;
	for(int i=1;i<=inb[N];i++)
		sort(sA+beg[i],sA+beg[i+1]),sort(As+beg[i],As+beg[i+1],cmp);
	memset(F,0x3f,sizeof(F));memset(G,0x3f,sizeof(G));
	for(int u=1;u<=inb[N];u++){
		for(int v=1;v<=inb[N];v++)if(u!=v){
			int i=beg[u],j=beg[v];
			while(i<beg[u+1]){
				while(j+1<beg[v+1]&&sA[j+1]<sA[i]) j++;
				mymin(F[As[i]][v],abs(sA[j]-sA[i]));
				if(j+1<beg[v+1]) mymin(F[As[i]][v],abs(sA[j+1]-sA[i]));
				i++;
			}
		}
		
		for(int i=beg[u];i<beg[u+1];i++){
			for(int v=u-1;v>1;v--) mymin(F[i][v-1],F[i][v]);
			for(int v=u+1;v<inb[N];v++) mymin(F[i][v+1],F[i][v]); 
		}
		for(int v=1;v<u;v++)
		for(int i=beg[u];i<beg[u+1]-1;i++) mymin(F[i+1][v],F[i][v]);
		for(int v=u+1;v<=inb[N];v++)
		for(int i=beg[u+1]-1;i>beg[u];i--) mymin(F[i-1][v],F[i][v]);
		
		for(int i=beg[u]+1;i<beg[u+1];i++) mymin(G[u][u],abs(sA[i]-sA[i-1]));
	}
	for(int u=1;u<=inb[N];u++)
	for(int v=u+1;v<=inb[N];v++)
		mymin(G[u][v],min(G[u][v-1],min(F[beg[v+1]-1][u],G[v][v])));
	
	scanf("%d",&M);
	while(M--){
		int L,R;scanf("%d%d",&L,&R);
		int ans=0x3f3f3f3f;
		if(inb[L]==inb[R]){
			int lst=-0x3f3f3f3f;
			for(int i=beg[inb[L]];i<beg[inb[L]+1];i++)
				if(L<=As[i]&&As[i]<=R) mymin(ans,abs(sA[i]-lst)),lst=sA[i];
		}
		else{
			if(inb[L]+1<=inb[R]-1)
				mymin(ans,G[inb[L]+1][inb[R]-1]),
				mymin(ans,min(F[R][inb[L]+1],F[L][inb[R]-1]));
			f.clear();g.clear();
			for(int i=beg[inb[L]];i<beg[inb[L]+1];i++) if(L<=As[i]) f.push_back(sA[i]);
			for(int i=beg[inb[R]];i<beg[inb[R]+1];i++) if(As[i]<=R) g.push_back(sA[i]);
			mymin(ans,Merge());
		} 
		printf("%d\n",ans);
	}
}