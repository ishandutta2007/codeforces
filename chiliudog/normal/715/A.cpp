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
i64 v1,v2,v11,v22;
inline i64 exgcd(i64 a,i64 b){
	if(b==0){
		v1=1;v2=0;return 1;
	}
	i64 tmp=exgcd(b,a%b);
	v11=v1;v22=v2;
	v1=v22;v2=v11-a/b*v22;
	return tmp;
}
int main(){
	i64 n;cin>>n;i64 last=2;
	rep(i,1,n){
		i64 v1;
//		assert(last%i==0);
		if(i==1)v1=2;else v1=1ll*i*i*i+2ll*i*i+1;
		printf("%I64d\n",v1);
//		last=sqrt(last+v1*i);
	}
	return 0;
}