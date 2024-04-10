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
inline bool cmp(pair<pin,int> a,pair<pin,int> b){
	return a.w1.w2-a.w1.w1<b.w1.w2-b.w1.w1;
}
const int maxn=300005;
pair<pin,int> a[maxn];
int n,m;
i64 sumA[maxn],sumB[maxn];
i64 ans[maxn];
int main(){
	read(n);read(m);
	rep(i,1,n){
		read(a[i].w1.w1),read(a[i].w1.w2);
		a[i].w2=i;
	}
	rep(i,1,m){
		int x,y;read(x);read(y);
		ans[x]-=min(a[x].w1.w1+a[y].w1.w2,a[x].w1.w2+a[y].w1.w1);
		ans[y]-=min(a[x].w1.w1+a[y].w1.w2,a[x].w1.w2+a[y].w1.w1);
	}sort(a+1,a+1+n,cmp);
	rep(i,1,n)sumB[i]=sumB[i-1]+a[i].w1.w2;
	per(i,n,1)sumA[i]=sumA[i+1]+a[i].w1.w1;
	rep(i,1,n){
		ans[a[i].w2]+=sumB[i-1]+1ll*a[i].w1.w1*(i-1);
		ans[a[i].w2]+=sumA[i+1]+1ll*a[i].w1.w2*(n-i);
	}
	rep(i,1,n)printf("%I64d ",ans[i]);
	return 0;
}