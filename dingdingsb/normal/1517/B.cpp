#include<bits/stdc++.h>
using namespace std;
const int N=110;
int t,n,m;
int b[N][N];
struct node{
	int st,id;
}e[N*N];
int ans[N][N];
signed main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);int cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++)
				scanf("%d",&b[i][j]),ans[i][j]=-1,e[++cnt]={i,j};
		}
		sort(e+1,e+1+cnt,[&](const node&x,const node&y)->bool{return b[x.st][x.id]<b[y.st][y.id];});
		for(int i=1;i<=m;i++)
			ans[e[i].st][i]=b[e[i].st][e[i].id],b[e[i].st][e[i].id]=-1;
		for(int i=1;i<=n;i++){
			int kk=1;
			for(int j=1;j<=m;j++){
				if(ans[i][j]!=-1)printf("%d ",ans[i][j]);
				else{
					while(b[i][kk]==-1)kk++;
					printf("%d ",b[i][kk]);kk++;
				}
			}
			puts("");
		}
	}
}