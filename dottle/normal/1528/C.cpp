#include<bits/stdc++.h>
#define _to e[i].to
const int N=600050,P=21;
using namespace std;
int n,t,ans;
struct graph{
	struct edge{
		int to,nx;
	}e[N];int hd[N],S;
	void add(int fr,int to){
		e[++S]=(edge){to,hd[fr]},hd[fr]=S;
	} 
	int is[N],os[N],dep[N],mn[P][N],ln[N],l[N],r[N],cnt,t;
	void input(){for(int i=2,y;i<=n;i++)scanf("%d",&y),add(y,i);}
	void clr(){for(int i=1;i<=n;i++)hd[i]=0;S=0,ans=0,t=0;}
	void dfs(int k,int fa){
		dep[k]=dep[fa]+1,l[k]=r[k]=++t;
		for(int i=hd[k];i;i=e[i].nx)if(_to!=fa) dfs(_to,k),r[k]=max(r[k],r[_to]);
	}
}A,B;
struct BIT{
	int a[N];
	void add(int k,int p){
		if(k)while(k<=n)a[k]+=p,k+=k&-k;
	}int sum(int k){
		int ans=0;while(k)ans+=a[k],k-=k&-k;return ans; 
	}void add(int l,int r,int p){
		add(l,p),add(r+1,-p);
	}void clr(){
		for(int i=0;i<=n;i++)a[i]=0;
	}
}I;

void dfsA(int k,int na){
	int p=I.sum(B.l[k]);
	if(p)na--,I.add(B.l[p],B.r[p],-p);
	ans=max(ans,na);
	I.add(B.l[k],B.r[k],k);
	for(int i=A.hd[k];i;i=A.e[i].nx)
		dfsA(A._to,na+1);
	I.add(B.l[k],B.r[k],-k);	
	if(p)I.add(B.l[p],B.r[p],p);	
}

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		A.input(),B.input();
		B.dfs(1,0);
		dfsA(1,1);
		printf("%d\n",ans);
		A.clr(),B.clr(),I.clr();
	} 
}