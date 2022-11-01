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
#define dg(...) fprintf(stderr,____VA_ARGS__);
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
const int maxn=1000005;
int cnt01,cnt00,cnt10,cnt11;
int num0,num1;
int ans[maxn];
inline bool check(int num0,int num1,int cnt01,int cnt10){
	if(cnt01+cnt10!=1ll*num0*num1){
		return 0;
	}int res=cnt01;
	clr(ans);
	per(i,num0,0){
		while(num1&&res>=i)res-=i,num1--,ans[i]++;
	}
	if(res)return 0;
	rep(i,0,num0){
		if(i)putchar('0');
		rep(k,1,ans[i])putchar('1');
	}return 1;
}
int main(){
//	judge();
	read(cnt00);read(cnt01);read(cnt10);read(cnt11);
	rep(x,1,100000){
		if(1ll*x*(x-1)/2==cnt00){
			num0=x;break;
		}
	}	
	rep(x,1,100000){
		if(1ll*x*(x-1)/2==cnt11){
			num1=x;break;
		}
	}if(num1==0||num0==0)return puts("Impossible"),0;
	if(check(num0,num1,cnt01,cnt10))return 0;
	if(num0==1){
		if(check(num0,num1,cnt01,cnt10))return 0;
		if(check(0,num1,cnt01,cnt10))return 0;
	}
	if(num1==1){
		if(check(num0,num1,cnt01,cnt10))return 0;
		if(check(num0,num1-1,cnt01,cnt10))return 0;
	}
	if(num1==1&&num0==1){
		if(check(num0-1,num1-1,cnt01,cnt10))return 0;
	}
	puts("Impossible");return 0;
	return 0;
}