#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define forE(i,x) for(int i=head[x];i!=-1;i=ne[i])
using namespace std;
typedef long long i64;
typedef unsigned long long u64;
typedef unsigned u32;
typedef pair<int,int> pin;
#define mk(a,b) make_pair(a,b)
#define lowbit(x) ((x)&(-(x)))
#define sqr(a) ((a)*(a))
#define clr(a) (memset((a),0,sizeof(a)))
#define ls ((x)<<1)
#define rs (((x)<<1)|1)
#define mid (((l)+(r))>>1)
#define pb push_back
#define w1 first
#define w2 second
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
/*******************************head*******************************/
const int maxn=100005;
char s[maxn][12];
const int BN=100;
int n,m,x[maxn][12],y[maxn][12],q;
inline void rebuild(int r1,int r2){
	rep(i,r1,r2)rep(j,1,m)x[i][j]=y[i][j]=-1;
	rep(i,1,m)if(s[r1][i]=='^')x[r1][i]=r1-1,y[r1][i]=i;
	rep(i,r1,r2)x[i][0]=i,y[i][0]=0,x[i][m+1]=i,y[i][m+1]=m+1;
	rep(i,r1,r2){
		rep(j,1,m){
			if(i!=r1&&s[i][j]=='^')x[i][j]=x[i-1][j],y[i][j]=y[i-1][j];
			else if(s[i][j]=='<')x[i][j]=x[i][j-1],y[i][j]=y[i][j-1];
		}
		per(j,m,1){
			if(s[i][j]=='>')x[i][j]=x[i][j+1],y[i][j]=y[i][j+1];
		}
	}
}
int main(){
    // judge();
	read(n);read(m);read(q);
	rep(i,1,n)rep(j,1,m){
		s[i][j]=getchar();
		while(s[i][j]!='<'&&s[i][j]!='>'&&s[i][j]!='^')s[i][j]=getchar();
	}
	for(int i=1;i<=n;i+=BN)
		rebuild(i,min(n,i+BN-1));
	while(q--){
		char ch=getchar();
		while(ch!='C'&&ch!='A')ch=getchar();
		int sx,sy;read(sx);read(sy);
		if(ch=='C'){
			s[sx][sy]=getchar();
			while(s[sx][sy]!='<'&&s[sx][sy]!='>'&&s[sx][sy]!='^')s[sx][sy]=getchar();
			rebuild((sx-1)/BN*BN+1,min(n,((sx-1)/BN+1)*BN));
		}else{int t;
			while(sx>0&&sy>0&&sy<=m)t=sx,sx=x[sx][sy],sy=y[t][sy];
			printf("%d %d\n",sx,sy);
		}
	}
    return 0;
}