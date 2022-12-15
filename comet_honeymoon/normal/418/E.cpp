#include<bits/stdc++.h>
using namespace std;

const int maxN=300005,maxLEN=170;

int N,M,LEN;
int A[maxN],val[maxN],n;
int inb[maxN];int beg[maxLEN];
int f[maxLEN][maxN],g[maxLEN][maxN]; 
int tf[maxN],tg[maxN];

int Opt[maxN],X[maxN],Y[maxN];

int main(){
	scanf("%d",&N);LEN=min(N,(int)(2*sqrt(N)));
	for(int i=1;i<=N;i++){
		scanf("%d",&A[i]);val[++n]=A[i];
		inb[i]=(i-1)/LEN+1;if(inb[i]!=inb[i-1]) beg[inb[i]]=i;
	} 
	beg[inb[N]+1]=N+1;
	scanf("%d",&M);
	for(int i=1;i<=M;i++){
		scanf("%d%d%d",&Opt[i],&X[i],&Y[i]);
		if(Opt[i]==1) val[++n]=X[i];
	}
	sort(val+1,val+n+1);n=unique(val+1,val+n+1)-val-1;
	
	for(int i=1;i<=M;i++) if(Opt[i]==1) X[i]=lower_bound(val+1,val+n+1,X[i])-val;
	for(int i=1;i<=N;i++){
		A[i]=lower_bound(val+1,val+n+1,A[i])-val;
		if(beg[inb[i]]==i)
			for(int j=1;j<=max(n,N);j++) f[inb[i]][j]=tf[j],g[inb[i]][j]=tg[j];
		tg[++tf[A[i]]]++;
	}
	
	for(int i=1;i<=M;i++){
		#define opt Opt[i]
		#define x X[i]
		#define y Y[i]
		if(opt==1){
			for(int j=inb[y]+1;j<=inb[N];j++)
				g[j][f[j][A[y]]--]--;
			A[y]=x;
			for(int j=inb[y]+1;j<=inb[N];j++)
				g[j][++f[j][A[y]]]++;
		} 
		else{
			if(x==1){printf("%d\n",val[A[y]]);continue;}
			for(int j=beg[inb[y]];j<=y;j++)
				g[inb[y]][++f[inb[y]][A[j]]]++;
			if(x%2==0) printf("%d\n",f[inb[y]][A[y]]);
			else printf("%d\n",g[inb[y]][f[inb[y]][A[y]]]);
			for(int j=beg[inb[y]];j<=y;j++)
				g[inb[y]][f[inb[y]][A[j]]--]--;
		}
	}
}