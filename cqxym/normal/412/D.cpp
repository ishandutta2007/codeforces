#include<stdio.h>
#include<set>
using namespace std;
#define R register int
int ans[50002];
set<int>Q[50001];
inline void Swap(int &x,int &y){
	int tem=x;
	x=y;
	y=tem;
}
int main(){
	int n,m,x,y;
	scanf("%d%d",&n,&m);
	for(R i=0;i!=m;i++){
		scanf("%d%d",&x,&y);
		Q[x].insert(y);
	}
	for(R i=1;i<=n;i++){
		ans[i]=x=i;
		while(x!=-1&&(Q[ans[x]].count(ans[x+1])|Q[ans[x-1]].count(ans[x]))==1){
			x--;
			Swap(ans[x],ans[x+1]);
		}
		if(x==-1){
			printf("-1");
			return 0;
		}
	}
	for(R i=1;i<=n;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}