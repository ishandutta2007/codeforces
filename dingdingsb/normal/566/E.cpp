#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int n;bitset<N>a[N];
bool flag[N];//
int m;//
bitset<N>e[N];//
bitset<N>l[N];//(
bool kk[N];
signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int k;scanf("%d",&k);
		for(int j=1,x;j<=k;j++)
			scanf("%d",&x),a[i][x]=true;
	}
	//
	{
		for(int i=2;i<=n;i++)
			if(a[i]!=a[1])goto loop;
		for(int i=2;i<=n;i++)
			printf("%d %d\n",1,i);
		exit(0);
	}
	loop:;
	//
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++){
			bitset<N>tmp=a[i]&a[j];
			if(tmp.count()==2){
				int x=tmp._Find_first();
				int y=tmp._Find_next(x);
				if(e[x][y])continue;
				if(!flag[x])flag[x]=1,m++;
				if(!flag[y])flag[y]=1,m++;
				e[x][y]=e[y][x]=1;
				printf("%d %d\n",x,y);
			}
		}
	//
	if(m==2){
		int x=-1,y=-1;
		for(int i=1;i<=n;i++)
			if(flag[i]){
				if(x==-1)x=i;
				else y=i;
			}
		for(int i=1;i<=n;i++)
			if(a[i].count()!=n){//xy
				//ixyx
				for(int j=1;j<=n;j++)
					if(a[i][j]&&j!=x&&j!=y)
						printf("%d %d\n",x,j),flag[j]=1;
				break;
			}
		for(int i=1;i<=n;i++)
			if(!flag[i])
				printf("%d %d\n",y,i);
		return 0;
	}
	//
	for(int i=1;i<=n;i++)if(!flag[i]){
		int mn=1e9,k=-1;
		for(int j=1;j<=n;j++)
			if(a[j][i]&&a[j].count()<mn&&!kk[j])
				k=j,mn=a[j].count();
		l[i]=a[k];kk[k]=true;
	}else e[i][i]=1;
	for(int i=1;i<=n;i++)if(!flag[i]){
		for(int j=1;j<=n;j++)if(!flag[j])l[i][j]=0;
		for(int j=1;j<=n;j++)if(flag[j]){
			if(l[i]==e[j]){
				printf("%d %d\n",i,j);
				break;
			}
		}
	}
}