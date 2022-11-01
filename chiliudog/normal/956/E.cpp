#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<cstring>
#include<vector>
#include<map>
#include<cassert>
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
const int maxn=10005;
struct info{
	int a,b;
	inline info(){}
	inline info(int _a,int _b){a=_a;b=_b;}
}v[maxn];	
inline bool operator < (const info &a,const info &b){
	if(a.b!=b.b){
		return a.b<b.b;
	}
	return a.a>b.a;
}
pair<int,int> f[2][maxn];
int l,n,r;
inline bool operator < (const pin &a,const pin &b){
	if(a.w1!=b.w1)return a.w1<b.w1;
	else return a.w2<b.w2;
}
inline pin operator + (const pin &a,const int &b){
	return mk(a.w1+b,a.w2);
}
int main(){
	read(n);read(l);read(r);
	rep(i,1,n)read(v[i].a);
	rep(i,1,n)read(v[i].b);
	sort(v+1,v+1+n);
	// rep(i,1,n)printf("%d %d\n",v[i].a,v[i].b);
	f[0][0]=mk(0,0);
	rep(i,1,r)f[0][i]=mk(-1e9,0);
	rep(i,1,n)rep(j,0,r){
		f[i&1][j]=mk(-1e9,0);
		f[i&1][j]=f[(i-1)&1][j];
		if(j>=v[i].a){
			f[i&1][j]=max(f[i&1][j],f[(i-1)&1][j-v[i].a]+(v[i].b*((j-v[i].a)>=l)));
		}
		if(f[i&1][j]==f[(i-1)&1][j])f[i&1][j].w2=max(f[i&1][j].w2,v[i].b);
	}int ans=0;
	rep(i,0,r){
		ans=max(ans,f[n&1][i].w1+(f[n&1][i].w2*(i>=l)));
	}cout<<ans<<endl;
	return 0;
}