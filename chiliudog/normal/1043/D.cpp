#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
#include<cassert>
#include<queue>
#include<cmath>
#include<queue>
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
int n,m,p[11][maxn],inv[11][maxn];
i64 f[maxn];
int main(){
	read(n);read(m);
	rep(i,1,m){
		rep(j,1,n)read(p[i][j]),inv[i][p[i][j]]=j;
	}f[1]=1;
	rep(i,2,n){
		f[i]=1;
		bool flag=1;
		rep(j,2,m){
			flag&=(p[j][inv[j][p[1][i]]-1]==p[1][i-1]);
		}if(flag)f[i]+=f[i-1];
	}i64 ans=0;
	rep(i,1,n)ans+=f[i];
	cout<<ans<<endl;
	return 0;
}