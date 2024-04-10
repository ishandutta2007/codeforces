#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define R register int
#define I inline
#define N 100001
vector<int>G[N],C[N],H[N];
int dep[N],g[448][N],fa[N],b[448],sz[N];
char ans[N];
bool f[448][N];
struct Painter{
	char Character;
	int LeftNum;
};
I void DFS(int x){
	dep[x]=dep[fa[x]]+1;
	C[dep[x]].push_back(x);
	sz[x]=1;
	for(vector<int>::iterator T=G[x].begin();T!=G[x].end();T++){
		DFS(*T);
		sz[x]+=sz[*T];
	}
}
I bool Compare(int x,int y){
	return sz[x]<sz[y];
}
I void Swap(Painter&A,Painter&B){
	Painter Tem=A;
	A=B;
	B=Tem;
}
int main(){
	Painter A,B;
	A.Character='a';
	B.Character='b';
	int n,maxdep=0;
	scanf("%d%d",&n,&A.LeftNum);
	B.LeftNum=n-A.LeftNum;
	for(int i=2;i<=n;i++){
		scanf("%d",fa+i);
		G[fa[i]].push_back(i);
	}
	DFS(1);
	for(R i=1;i<=n;i++){
		if(dep[i]>maxdep){
			maxdep=dep[i];
		}
	}
	for(int i=1;i<=maxdep;i++){
		H[C[i].size()].push_back(i);
	}
	f[0][0]=true;
	int tot=0;
	for(R i=1;i<=n;i++){
		if(H[i].empty()==false){
			tot++;
			b[tot]=i;
			int ct=H[i].size();
			for(R j=0;j!=i;j++){
				f[tot][j]=f[tot-1][j];
			}
			for(R j=i;j<=n;j++){
				if(f[tot-1][j]==true){
					f[tot][j]=true;
				}else{
					if(f[tot][j-i]==true){
						g[tot][j]=g[tot][j-i]+1;
						if(g[tot][j]<=ct){
							f[tot][j]=true;
						}
					}
				}
			}
		}
	}
	if(f[tot][A.LeftNum]==true){
		printf("%d\n",maxdep);
		int p=A.LeftNum;
		for(R i=1;i<=n;i++){
			ans[i]='b';
		}
		for(R i=tot;i!=0;i--){
			int t=g[i][p];
			p-=t*b[i];
			for(R j=0;j!=t;j++){
				int d=H[b[i]][j];
				for(vector<int>::iterator T=C[d].begin();T!=C[d].end();T++){
					ans[*T]='a';
				}
			}
		}
	}else{
		printf("%d\n",maxdep+1);
		for(R i=1;i<=maxdep;i++){
			sort(C[i].begin(),C[i].end(),Compare);
			if(A.LeftNum<B.LeftNum){
				Swap(A,B);
			}
			while(C[i].empty()==false&&A.LeftNum!=0){
				ans[C[i].back()]=A.Character;
				A.LeftNum--;
				C[i].pop_back();
			}
			while(C[i].empty()==false){
				ans[C[i].back()]=B.Character;
				B.LeftNum--;
				C[i].pop_back();
			}
		}
	}
	for(R i=1;i<=n;i++){
		putchar(ans[i]);
	}
	return 0;
}