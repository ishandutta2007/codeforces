#include<stdio.h>
#include<vector>
using namespace std;
#define R register int
#define I inline
#define N 1000001
char BF[N],*p1,*p2;
#define GC (p1==p2&&(p2=(p1=BF)+fread(BF,1,N,stdin),p1==p2)?0:*p1++)
I void Read(int&x){
    char t=GC;
    x=0;
    while(t<48||t>57){
        t=GC;
    }
    while(t>47&&t<58){
        x=x*10+(t^48);
        t=GC;
    }
}
vector<int>G[N],S[N];
int dep[N],h[N],maxdep[N],Top[N],f[N],ans[N],sum[N];
I void PreDFS(int x,int F){
	maxdep[x]=dep[x]=dep[F]+1;
	f[x]=F;
	for(vector<int>::iterator T=G[x].begin();T!=G[x].end();T++){
		if(*T!=F){
			PreDFS(*T,x);
			if(maxdep[*T]>maxdep[x]){
				maxdep[x]=maxdep[*T];
				h[x]=*T;
			}
		}
	}
}
I void ReDFS(int x,int t){
	Top[x]=t;
	S[t].push_back(x);
	sum[x]++;
	if(h[x]!=0){
		ReDFS(h[x],t);
		int l=dep[x]-dep[t],ansh;
		ansh=S[t][l+1+ans[h[x]]];
		if(sum[ansh]>1){
			ans[x]=ans[h[x]]+1;
		}
		for(vector<int>::iterator T=G[x].begin();T!=G[x].end();T++){
			int v=*T;
			if(v!=h[x]&&v!=f[x]){
				ReDFS(v,v);
				int d=1;
				for(vector<int>::iterator T2=S[v].begin();T2!=S[v].end();T2++){
					int&tem=sum[S[t][l+d]],&tem2=sum[S[t][l+ans[x]]];
					tem+=sum[S[v][d-1]];
					if(tem>tem2||tem==tem2&&d<ans[x]){
						ans[x]=d;
					}
					d++;
				}
			}
		}
	}
}
int main(){
	int n,x,y;
	Read(n);
	for(R i=1;i!=n;i++){
		Read(x);
		Read(y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	PreDFS(1,0);
	ReDFS(1,1);
	for(R i=1;i<=n;i++){
		printf("%d\n",ans[i]);
	}
	return 0;
}