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
typedef double ld;
int main(){
	i64 k,d,t;
	cin>>k>>d>>t;
	i64 prod=(k-1)/d+1;
	i64 x=k;
	i64 y=prod*d-x;
	i64 tot=2*t/(2*x+y);
	ld res=1-(tot)*(x*1./t+y*0.5/t);
	ld ans=tot*(x+y);
	if(x*1./t>res){
		ans+=res/(1./t);
	}else{
		res-=x*1./t;
		ans+=x;
		ans+=res/(0.5/t);
	}
	printf("%.10f\n",ans);
	return 0;
}