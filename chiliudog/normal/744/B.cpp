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
const int maxn=1005;
int n,maxi[maxn];
int v[maxn][20][2],t=0;
int main(){
    // judge();
	read(n);
	rep(i,0,9){
		vector<int> tmp1;
		rep(j,1,n)if(j&(1<<i))tmp1.pb(j);
		if(tmp1.size()){
			printf("%d\n",tmp1.size());
			for(int v:tmp1)printf("%d ",v);fflush(stdout);
			rep(j,1,n)read(v[j][i][1]);
		}else{
			rep(j,1,n)v[j][i][1]=2e9;
		}
		tmp1.clear();
		rep(j,1,n)if(!(j&(1<<i)))tmp1.pb(j);
		if(tmp1.size()){
			printf("%d\n",tmp1.size());
			for(int v:tmp1)printf("%d ",v);fflush(stdout);
			rep(j,1,n)read(v[j][i][0]);
		}else{
			rep(j,1,n)v[j][i][0]=2e9;
		}
	}puts("-1");fflush(stdout);
	rep(i,1,n){int res=2e9;
		rep(j,0,9){
			int x=(i>>j)&1;
			x^=1;
			res=min(res,v[i][j][x]);
		}
		printf("%d ",res);
	}fflush(stdout);
    return 0;
}