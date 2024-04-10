#include<stdio.h>
#include<vector>
using namespace std;
#define R register int
#define I inline
#define N 400001
char s[N];
vector<char>S[N];
vector<bool>V[N];
vector<int>Lf[N],Rt[N];
int a[N],r[N];
inline void DFS(int x,int y,const bool type,const int t,const int n,const int m){
	if(V[x][y]==false){
		V[x][y]=true;
		if(type==true){
			Rt[x][y]=t;
		}else{
			Lf[x][y]=t;
		}
		if(x!=0&&S[x-1][y]=='#'){
			DFS(x-1,y,type,t,n,m);
		}
		if(x!=n-1){
			DFS(x+1,y,type,t,n,m);
		}
		if(y!=0&&S[x][y-1]=='#'){
			DFS(x,y-1,type,t,n,m);
		}
		if(y!=m-1&&S[x][y+1]=='#'){
			DFS(x,y+1,type,t,n,m);
		}
	}
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(R i=0;i!=n;i++){
		S[i].resize(m);
		V[i].resize(m);
		Lf[i].resize(m);
		Rt[i].resize(m);
		scanf("%s",s);
		for(R j=0;j!=m;j++){
			S[i][j]=s[j];
		}
	}
	for(R i=m-1;i!=-1;i--){
		for(R j=0;j!=n;j++){
			if(S[j][i]=='#'){
				DFS(j,i,true,i,n,m);
			}
		}
	}
	for(R i=0;i!=n;i++){
		for(R j=0;j!=m;j++){
			V[i][j]=false;
		}
	}
	for(R i=0;i!=m;i++){
		scanf("%d",a+i);
		for(R j=0;j!=n;j++){
			if(S[j][i]=='#'){
				DFS(j,i,false,i,n,m);
			}
		}
		r[i]=N;
	}
	for(R i=0;i!=m;i++){
		if(a[i]!=0){
			int ct=0,p=n,l;
			while(ct!=a[i]){
				p--;
				if(S[p][i]=='#'){
					ct++;
				}
			}
			l=Lf[p][i];
			if(Rt[p][i]<r[l]){
				r[l]=Rt[p][i];
			}
		}
	}
	int cur=N,ans=0;
	for(R i=0;i!=m;i++){
		if(r[i]<cur){
			cur=r[i];
		}
		if(i==cur){
			ans++;
			cur=N;
		}
	}
	printf("%d",ans);
	return 0;
}