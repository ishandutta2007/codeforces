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
int a[maxn],n,l,x,y;
set<int> w;
bool flag1=0,flag2=0;
int main(){
    // judge();
	read(n);read(l);read(x);read(y);
	rep(i,1,n)read(a[i]);
	rep(i,1,n)w.insert(a[i]);
	rep(i,1,n){
		if(w.count(a[i]-x))flag1=1;
		if(w.count(a[i]+x))flag1=1;
		if(w.count(a[i]-y))flag2=1;
		if(w.count(a[i]+y))flag2=1;
	}
	if(flag1&&flag2){
		puts("0");return 0;
	}
	if(flag1||flag2){
		if(flag1){
			printf("1\n%d\n",y);
		}else{
			printf("1\n%d\n",x);
		}
		return 0;
	}
	rep(i,1,n){
		if(w.count(a[i]+x+y)){
			printf("1\n%d\n",a[i]+x);
			return 0;
		}
	}
	rep(i,1,n){
		if(w.count(a[i]+y-x)){
			if(a[i]>=x){
				printf("1\n%d\n",a[i]-x);
				return 0;
			}
			if(a[i]+y<=l){
				printf("1\n%d\n",a[i]+y);
				return 0;
			}
		}
	}
	printf("2\n%d %d\n",x,y);
    return 0;
}