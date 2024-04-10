#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define forE(i,x) for(int i=head[x];i!=-1;i=ne[i])
using namespace std;
typedef long long int64;
#define mk(a,b) make_pair(a,b)
#define w1 first
#define w2 second
typedef pair<int,int> pin;
const int maxn=30005,maxm=205;
int f[maxn][maxm][2],g[maxn][maxm][2],n,k;
const int inf=1<<29;
inline void read(int &x){
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
inline void judge(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
}

int main(){
   // judge();
	read(n);read(k);
	rep(i,1,k)rep(j,0,i)f[0][i][j]=g[0][i][j]=-inf;
	rep(i,1,n){
		int x;read(x);
		rep(j,1,k){
			int QAQ=2-(j==1||j==k);
			f[i][j][0]=max(f[i-1][j][0]+QAQ*x,g[i-1][j-1][1]+QAQ*x);
			f[i][j][1]=max(f[i-1][j][1]-QAQ*x,g[i-1][j-1][0]-QAQ*x);
			g[i][j][0]=max(f[i][j][0],g[i-1][j][0]);
			g[i][j][1]=max(f[i][j][1],g[i-1][j][1]);
			if(j>1&&j<k){
				g[i][j][0]=max(g[i][j][0],g[i-1][j-1][0]);
				g[i][j][1]=max(g[i][j][1],g[i-1][j-1][1]);
			}
		}
	}
	cout<<max(g[n][k][0],g[n][k][1]);
    return 0;
}