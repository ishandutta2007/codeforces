#include<stdio.h>
#include<set>
using namespace std;
#define R register int
#define L long long
#define I inline
#define N 200001
set<int>Q[31];
int g[N],a[N],cand[31][2];
L c[N],sum[N];
I void Add(int x,int d,int&n){
	for(R i=x;i<=n;i+=i&-i){
		c[i]+=d;
	}
}
I L GetSum(int x){
	L res=0;
	for(R i=x;i!=0;i-=i&-i){
		res+=c[i];
	}
	return res;
}
I int GetG(int x){
	int res=0;
	while(x!=0){
		res++;
		x>>=1;
	}
	return res;
}
I void InitCand(int x){
	cand[x][0]=cand[x][1]=-1;
	set<int>::iterator T=Q[x].begin();
	for(R i=0;i!=2&&T!=Q[x].end();T++){
		cand[x][i]=*T;
		sum[*T]=GetSum(*T-1);
		i++;
	}
}
I int Calc(int x,int d,int modi){
	int res=-1;
	for(R i=0;i!=2;i++){
		int tem=cand[x][i];
		if(tem==-1){
			return res;
		}
		if(tem>d){
			sum[tem]+=modi;
		}
		if(sum[tem]==a[tem]){
			res=tem;
		}
	}
	return res;
}
int main(){
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		g[i]=GetG(a[i]);
		Q[g[i]].insert(i);
		Add(i,a[i],n);
	}
	for(R i=0;i!=31;i++){
		InitCand(i);
	}
	for(R i=0;i!=q;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		set<int>::iterator T=Q[g[x]].lower_bound(x);
		Q[g[x]].erase(T);
		InitCand(g[x]);
		int modi=y-a[x];
		g[x]=GetG(y);
		Q[g[x]].insert(x);
		InitCand(g[x]);
		Add(x,modi,n);
		a[x]=y;
		int tag=-1;
		for(R i=0;i!=31;i++){
			int t=Calc(i,x,modi);
			if(t!=-1){
				tag=t;
			}
		}
		printf("%d\n",tag);
	}
	return 0;
}