#include<stdio.h>
#include<vector>
using namespace std;
#define R register int
struct Edge{
	int End,lab,id;
};
vector<Edge>G[200001];
int ans[200000];
bool v[200000];
int main(){
	int n,x,y;
	scanf("%d",&n);
	Edge Tem;
	Tem.lab=-1;
	for(R i=1;i!=n;i++){
		scanf("%d%d",&x,&y);
		Tem.id=i;
		Tem.End=y;
		G[x].push_back(Tem);
		Tem.End=x;
		G[y].push_back(Tem);
	}
	x=0;
	for(R i=1;i<=n;i++){
		if(G[i].size()>x){
			x=G[i].size();
			y=i;
		}
	}
	if(x>2){
		ans[G[y][0].id]=0;
		ans[G[y][1].id]=1;
		ans[G[y][2].id]=2;
		v[G[y][0].id]=true;
		v[G[y][1].id]=true;
		v[G[y][2].id]=true;
		x=3;
		for(R i=1;i<=n;i++){
			y=G[i].size();
			for(R j=0;j!=y;j++){
				if(v[G[i][j].id]==false){
					ans[G[i][j].id]=x;
					v[G[i][j].id]=true;
					x++;
				}
			}
		}
		for(R i=1;i!=n;i++){
			printf("%d\n",ans[i]);
		}
	}else{
		for(R i=0;i!=n-1;i++){
			printf("%d\n",i);
		}
	}
	return 0;
}