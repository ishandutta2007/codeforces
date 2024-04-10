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
const int maxn=5005;
int f[maxn][maxn];const int mod=1e9+7;
inline void add(int &x,int y){
	x+=y;if(x>=mod)x-=mod;
}
inline void dec(int &x,int y){
	x-=y;if(x<0)x+=mod;
}
int n,k,a,b;
int main(){
    // judge();
	read(n);read(a);read(b);read(k);//k--;
	f[0][a]=1;
	rep(i,0,k-1){
		rep(j,1,n)if(f[i][j]){
			if(j<b){
				int l=max(1,j-(b-j)+1);
				int r=b-1;
				add(f[i+1][l],f[i][j]);
				dec(f[i+1][r+1],f[i][j]);
				dec(f[i+1][j],f[i][j]);
				add(f[i+1][j+1],f[i][j]);
			}
			if(j>b){
				int l=b+1;
				int r=min(n,j+(j-b)-1);
				add(f[i+1][l],f[i][j]);
				dec(f[i+1][r+1],f[i][j]);
				dec(f[i+1][j],f[i][j]);
				add(f[i+1][j+1],f[i][j]);
			}
		}
		rep(j,2,n)add(f[i+1][j],f[i+1][j-1]);
	}
	int res=0;
	rep(j,1,n)add(res,f[k][j]);
	cout<<res<<endl;
    return 0;
}