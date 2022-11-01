#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
#include<cassert>
#include<queue>
#include<cmath>
#include<queue>
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
const int maxn=150005;
int a[maxn],b[maxn],n;
i64 v[maxn];
inline i64 gcd(i64 a,i64 b){
	return b==0?a:gcd(b,a%b);
}
int main(){
	read(n);
	rep(i,1,n)read(a[i]),read(b[i]);
	rep(i,1,n){
		v[i]=1ll*a[i]*b[i]/gcd(a[i],b[i]);
	}
	i64 all=v[1];
	rep(i,2,n){
		all=gcd(all,v[i]);
	}
	if(all>1){
		rep(i,1,n){
			if(gcd(all,a[i])>1){
				all=gcd(all,a[i]);
			}else{
				all=gcd(all,b[i]);
			}
		}
		rep(i,2,100000){
			if(all%i==0){
				cout<<i<<endl;
				return 0;
			}
		}
		cout<<all<<endl;
		return 0;
	}else{
		puts("-1");
	}
	return 0;
}