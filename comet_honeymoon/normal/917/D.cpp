#include<bits/stdc++.h>
using namespace std;

const int tt=1000000007;
int qpow(int a,int k){
	int ans=1;
	while(k){
		if(k&1) ans=1LL*ans*a%tt;
		a=1LL*a*a%tt;
		k>>=1;
	}
	return ans;
}
struct mat{
    int n,m;
    int a[105][105];
    void Gauss(int p,int &flg){
        if(p==n) return;
        if(!a[p][p])
            for(int i=p+1;i<=m;i++)
            if(a[i][p]){
                swap(a[i],a[p]);flg++;break;
            }
        if(!a[p][p]) return;
        for(int i=p+1;i<=m;i++){
            int tmp=1LL*a[i][p]*qpow(a[p][p],tt-2)%tt;
            for(int j=p;j<=m;j++)
                a[i][j]=(a[i][j]-1LL*a[p][j]*tmp%tt+tt)%tt;
        }
        Gauss(p+1,flg);
    }
    int Det(){
        int flg=0,ANS=1;
        Gauss(1,flg);
        for(int i=1;i<=n;i++) ANS=1LL*ANS*a[i][i]%tt;
        return ((flg&1)^(n&1))?(-ANS+tt)%tt:ANS;
    }
}ans;

int N;
bool G[105][105];
int Y[105];
int ANS[105];
int main(){
	scanf("%d",&N);
	for(int i=1;i<N;i++){
		int u,v;scanf("%d%d",&u,&v);
		G[u][v]=G[v][u]=1;
	} 
	for(int x=1;x<=N;x++){
		ans.n=ans.m=N-1;
		memset(ans.a,0,sizeof(ans.a));
		for(int u=1;u<=N;u++)
		for(int v=u+1;v<=N;v++){
			int w=(G[u][v]?x:1);
			ans.a[u][v]=(ans.a[u][v]+w)%tt;
			ans.a[v][u]=(ans.a[v][u]+w)%tt;
			ans.a[u][u]=(ans.a[u][u]-w+tt)%tt;
			ans.a[v][v]=(ans.a[v][v]-w+tt)%tt;
		}
		Y[x]=ans.Det();//printf("%d\n",Y[x]);
	}
	ans.n=N,ans.m=N+1;
	for(int x=1;x<=N;x++){
		ans.a[x][N+1]=Y[x];
		for(int i=1,mul=1;i<=N;i++) ans.a[x][i]=mul,mul=1LL*mul*x%tt;
	}
//	for(int i=1;i<=N;i++){
//		for(int j=1;j<=N+1;j++) printf("%d ",ans.a[i][j]);
//		printf("\n");
//	}
	int flg=0;
	ans.Gauss(1,flg);
	for(int i=N;i>=1;i--){
		ANS[i]=ans.a[i][N+1];
		for(int j=i+1;j<=N;j++)
			ANS[i]=(ANS[i]-1LL*ans.a[i][j]*ANS[j]%tt+tt)%tt;
		ANS[i]=1LL*ANS[i]*qpow(ans.a[i][i],tt-2)%tt;
	}
	for(int i=1;i<=N;i++) printf("%d ",ANS[i]);
}