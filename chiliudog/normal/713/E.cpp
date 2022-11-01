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
const int maxn=200005;
int n,m,M,p,s,a[maxn],b[maxn],f[maxn];
const int inf=1<<30;

inline bool check(int x){
	f[1]=1;f[0]=-inf;
	rep(i,2,n){
		f[i]=-inf;
		if(f[i-1]>=a[i]-1)f[i]=a[i]+x;
		if(f[i-1]>=a[i]-x-1)f[i]=max(f[i],a[i]);
		if(f[i-2]>=a[i]-x-1)f[i]=max(f[i],a[i-1]+x);
	}
	if(f[n]>=m-x)return 1;
	if(a[2]-a[1]-1>x+x)return 0;
	f[1]=x+1;f[2]=max(a[2],f[1]);
	rep(i,3,n){
		f[i]=-inf;
		if(f[i-1]>=a[i]-1)f[i]=a[i]+x;
		if(f[i-1]>=a[i]-x-1)f[i]=max(f[i],a[i]);
		if(f[i-2]>=a[i]-x-1)f[i]=max(f[i],a[i-1]+x);
	}
	if(f[n]>=min(m,m+a[2]-x-1))return 1;return 0;
}

int main(){
	read(m);read(n);
	rep(i,1,n)read(a[i]),b[i]=a[i];
	rep(i,n+1,n<<1)b[i]=b[i-n]+m;
	if(n==1){
		cout<<m-1;
		return 0;
	}
	M=a[1]-a[n]+m;p=1;
	rep(i,2,n){
		if(a[i]-a[i-1]>M){
			M=a[i]-a[i-1];
			p=i;
		}
	}	
	M--;
	s=a[1]=1;
	rep(i,2,n){
		p++;
		s+=b[p]-b[p-1];
		a[i]=s;
	}
	int l=0,r=M,ans;
	while(l<=r){
		int md=(l+r)>>1;
		if(check(md))ans=md,r=md-1;else l=md+1;
	}cout<<ans;
}