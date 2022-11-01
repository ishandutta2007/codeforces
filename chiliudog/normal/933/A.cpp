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
const int maxn=2005;
int n,a[maxn],suma[maxn],sumb[maxn],pr[maxn],sf[maxn];
inline int query1(int l,int r){
	return suma[r]-suma[l-1];
}
inline int query2(int l,int r){
	return sumb[r]-sumb[l-1];
}
int main(){
	read(n);
	rep(i,1,n)read(a[i]);
	rep(i,1,n)suma[i]=suma[i-1]+(a[i]==1);
	rep(i,1,n)sumb[i]=sumb[i-1]+(a[i]==2);
	rep(i,1,n){
		rep(j,0,i)pr[i]=max(pr[i],query1(1,j)+query2(j+1,i));
	}
	rep(i,1,n){
		rep(j,i-1,n)sf[i]=max(sf[i],query1(i,j)+query2(j+1,n));
	}
	int ans=0;
	rep(i,1,n)ans=max(ans,pr[i-1]+sf[i]);
	cout<<ans;
	return 0;
}