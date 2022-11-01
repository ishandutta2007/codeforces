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
int a[maxn],B[maxn],n,d,b;
inline bool check(int k){
	int resk=k;
	int lend=(n+1)>>1,curpos=1;
	int res=0;
	rep(i,1,n)a[i]=B[i];
	rep(i,1,lend){
		if(resk){
			resk--;
			continue;
		}
		int res=b;
		while(curpos<=n&&1ll*curpos-i<=1ll*(i)*d){
			int del=min(a[curpos],res);
			res-=del;a[curpos]-=del;
			if(res==0)break;
			curpos++;
		}assert(res>=0);
		if(res)return 0;
	}resk=k;curpos=n;
	per(i,n,lend+1){
		if(resk){
			resk--;continue;
		}
		int res=b;
		while(curpos>=1&&1ll*i-curpos<=1ll*((n-i+1))*d){
			int del=min(a[curpos],res);
			res-=del;a[curpos]-=del;
			if(res==0)break;
			curpos--;
		}assert(res>=0);
		if(res)return 0;
	}
	return 1;
}
int main(){
	read(n);read(d);read(b);
	rep(i,1,n)read(B[i]);
	int l=0,r=n,ans;
	while(l<=r){
		int md=(l+r)>>1;
		if(check(md)){
			ans=md;r=md-1;
		}else{
			l=md+1;
		}
	}cout<<ans<<endl;
	return 0;
}