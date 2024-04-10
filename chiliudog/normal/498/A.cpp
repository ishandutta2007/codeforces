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
#define x1 x23123
#define x2 x34324
#define y1 y1212312
#define y2 y423423
const int maxn=10005;
i64 a[maxn],b[maxn],c[maxn];
i64 x1,y1,x2,y2;
int n;
int main(){
    // judge();
	cin>>x1>>y1;
	cin>>x2>>y2;
	read(n);
	rep(i,1,n)cin>>a[i]>>b[i]>>c[i];int ans=0;
	rep(i,1,n){
		i64 v1=x1*a[i]+y1*b[i]+c[i];
		i64 v2=x2*a[i]+y2*b[i]+c[i];
		if((v1>0&&v2<0)||(v1<0&&v2>0))ans++;
	}cout<<ans;
    return 0;
}