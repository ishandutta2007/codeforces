#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define R register int
vector<int>G[100001];
int dep[100001],f[100001];
inline void Tarjan(int x,int F,const int k,vector<int>&A,vector<int>&B){
	dep[x]=dep[F]+1;
	f[x]=F;
	if((dep[x]&1)==1){
		A.push_back(x);
	}else{
		B.push_back(x);
	}
	for(int T:G[x]){
		if(dep[T]==0){
			Tarjan(T,x,k,A,B);
		}else if(T!=F&&dep[T]<dep[x]&&dep[x]-dep[T]<k){
			printf("2\n%d\n",dep[x]-dep[T]+1);
			for(R i=x;i!=T;i=f[i]){
				printf("%d ",i);
			}
			printf("%d",T);
			exit(0);
		}
	}
}
int main(){
	int n,m,k,x,y;
	scanf("%d%d%d",&n,&m,&k);
	for(R i=0;i!=m;i++){
		scanf("%d%d",&x,&y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	vector<int>A[2];
	Tarjan(1,0,k,A[0],A[1]);
	x=A[0].size()>A[1].size()?0:1;
	puts("1");
	k=k+1>>1;
	for(R i=0;i!=k;i++){
		printf("%d ",A[x][i]);
	}
	return 0;
}