#include<iostream>
#include<cstring>
#include<cmath>
#include<map>
#include<queue>
#include<stack>
#include<cstdio>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(int i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const int N=1e3+7;
const int INF=1e9+7;
int to[N],a[N][N],b[N];
int n;

int main(){
	scanf("%d",&n);
	rep(i,n)scanf("%d",&to[i]);
	bool flag=1;
	rep(i,n)if(to[i]!=i){flag=0; break;}
	if(flag){
		printf("%d\n",n);
		rep(i,n){
			rep(j,n)printf(".");
			printf("\n");
		}
		return 0;
	}
	printf("%d\n",n-1);
	int ls=0;
	rep(i,n)if(to[i]==1)ls=i,to[i]=-1;
	a[n][ls]=1;
	for(int i=n-1;i;i--){
		int flag=0;
		rep(j,n)if(to[j]!=j)flag++;
		if(flag==1)break;
		int id=0;
		rep(j,n)if(to[j]<0)id=j;
		if(id==1){
			int v=0;
			REP(j,2,n)if(to[j]<j){v=j; break;}
			int q=to[v];
			a[i][1]=a[i][v]=a[i][q]=1;
			to[1]=to[q];
			to[q]=to[v];
			to[v]=-1;
		}
		else{
			int v;
			rep(j,n)if(to[j]==id)v=j;
			if(v>id)a[i][v]=a[i][id]=1;
			else a[i][v]=a[i][id]=2;
			swap(to[v],to[id]);
		}
	}
	rep(i,n){
		rep(j,n){
			char k;
			switch(a[i][j]){
				case 0:k='.'; break;
				case 1:k=92; break;
				case 2:k='/'; break;
			}
			printf("%c",k);
		}
		printf("\n");
	}
	return 0;
}
//7 2 5 3 4 1 7 6