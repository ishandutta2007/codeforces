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
const int maxn=100000000/32+50;
unsigned a[maxn];
u32 n,A,b,c,d,ans=0;
inline int query(int x){
	// assert(x<=100000001);
	return (a[x>>5]>>(x&31))&1;
}
inline void modify(int x){
	// assert(x<=100000001);
	a[x>>5]|=1u<<(x&31);
}
inline int get(int x){
	// assert(x<=3e8);
	// if((x&1)==0||x%3==0)return 0;
	int res=x/6;res*=2;
	// if(x%6==1)x+=0;
	if(x%6==5)res+=1;
	return res;
}
inline void go(int x){
	int cur=x+x;
	while(cur<=300000000){
		if(cur%2!=0&&cur%3!=0)modify(get(cur));
		cur+=x;
	}
	u32 res=0,f=0;
	f=((A*x+b)*x+c)*x+d;
	cur=1;
	while(1ll*cur*x<=n){
		cur*=x;
		res+=f*(n/cur);
	}
	ans+=res;
}
inline void solve(){
	go(2);go(3);
	rep(i,4,300000000){
		if(i%2==0||i%3==0)continue;
		if(query(get(i))==0){
			go(i);
		}
	}
}
int main(){
	// u32 n,a,b,c,d;
	cin>>n>>A>>b>>c>>d;
	solve();
	cout<<ans<<endl;
	return 0;
}