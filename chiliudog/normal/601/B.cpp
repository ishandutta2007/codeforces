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
#define dg(...) fprintf(stderr,__VA_ARGS__);
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
int m,a[maxn],v[maxn],n,q,d[maxn],S[maxn],top,ul[maxn],ur[maxn];
inline i64 solve(int l,int r){
	m=r-l+1;
	rep(i,l,r)v[i-l+1]=a[i];
	rep(i,1,m-1)d[i]=abs(v[i+1]-v[i]);S[0]=0;top=0;
	rep(i,1,m-1){
		while(top&&d[S[top]]<d[i])top--;
		ul[i]=S[top]+1;S[++top]=i;
	}top=0;S[0]=m;
	per(i,m-1,1){
		while(top&&d[S[top]]<=d[i])top--;
		ur[i]=S[top];S[++top]=i;
	}i64 res=0;
	rep(i,1,m-1){
		res+=1ll*d[i]*(i-ul[i]+1)*(ur[i]-i);
	}return res;
}
int main(){
	read(n);read(q);
	rep(i,1,n)read(a[i]);
	rep(i,1,q){
		int x,y;read(x);read(y);
		cout<<solve(x,y)<<endl;
	}
	return 0;
}