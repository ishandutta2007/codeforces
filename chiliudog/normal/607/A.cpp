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
pin a[maxn];
int n;
int f[maxn],ans=0;
inline int check(int x){
	int l=0,r=n,ans=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(a[mid].w1<x){
			ans=mid;l=mid+1;
		}else r=mid-1;
	}return ans;
}
int main(){
	read(n);rep(i,1,n)read(a[i].w1),read(a[i].w2);
	sort(a+1,a+1+n);
	rep(i,1,n){
		int x=check(a[i].w1-a[i].w2);
		f[i]=f[x]+1;ans=max(ans,f[i]);
	}printf("%d\n",n-ans);
	return 0;
}