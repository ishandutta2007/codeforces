#include<stdio.h>
#include<vector>
using namespace std;
#define R register int
#define I inline
#define N 100001
vector<int>G[N],C;
int sz[N];
I void Max(int&x,int y){
	x=x>y?x:y;
}
I void FindCen(int x,int F,int&n){
	int m=0;
	sz[x]=1;
	for(vector<int>::iterator T=G[x].begin();T!=G[x].end();T++){
		if(*T!=F){
			FindCen(*T,x,n);
			sz[x]+=sz[*T];
			Max(m,sz[*T]);
		}
	}
	Max(m,n-sz[x]);
	if(m<<1<=n){
		C.push_back(x);
	}
}
I void FindLeaf(int x,int F,int&a,int&b){
	if(a!=0){
		return;
	}
	bool tag=false;
	for(vector<int>::iterator T=G[x].begin();T!=G[x].end();T++){
		if(*T!=F){
			tag=true;
			FindLeaf(*T,x,a,b);
		}
	}
	if(tag==false){
		a=x;
		b=F;
	}
}
I void Solve(){
	int n,x,y;
	scanf("%d",&n);
	for(R i=1;i<=n;i++){
		G[i].clear();
	}
	C.clear();
	for(R i=1;i!=n;i++){
		scanf("%d%d",&x,&y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	FindCen(1,0,n);
	if(C.size()==1){
		x=G[1][0];
		printf("%d 1\n1 %d\n",x,x);
		return;
	}
	x=y=0;
	FindLeaf(C[1],C[0],x,y);
	printf("%d %d\n%d %d\n",x,y,x,C[0]);
}
int main(){
	int t;
	scanf("%d",&t);
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}