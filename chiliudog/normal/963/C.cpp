#include<iostream>
#include<cstdio>
#include<cstring>
#include<unordered_map>  
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
const int maxn=200005;
set<i64> zbl,zbr;
map<pair<i64,i64>,i64> e;
inline i64 gcd(i64 x,i64 y){
	if(y==0)return x;
	return gcd(y,x%y);
}
int n;
int main(){
	read(n);
	i64 stw=0,sth=0;
	rep(i,1,n){
		i64 w,h,c;
		cin>>w>>h>>c;
		zbl.insert(w);
		zbr.insert(h);
		e[mk(w,h)]=c;
		stw=w;sth=h;
	}
	for(i64 x:zbl)for(i64 y:zbr){
		if(!e.count(mk(x,y))){
			puts("0");
			return 0;
		}
	}
	for(i64 x:zbl)for(i64 y:zbr){
		if(x==stw||y==sth)continue;
		i64 s1=e[mk(stw,sth)],s2=e[mk(stw,y)],s3=e[mk(x,sth)],s4=e[mk(x,y)];
		i64 gcd1=gcd(s1,s2);
		s1/=gcd1;s2/=gcd1;
		gcd1=gcd(s4,s3);
		s4/=gcd1;s3/=gcd1;
		if(s1!=s3||s2!=s4){
			puts("0");
			return 0;
		}
	}
	i64 v1=e[mk(stw,sth)],v2=e[mk(stw,sth)];
	for(i64 y:zbr){
		v1=gcd(v1,e[mk(stw,y)]);
	}
	for(i64 x:zbl){
		v2=gcd(v2,e[mk(x,sth)]);
	}
	i64 val=e[mk(stw,sth)];
	i64 tmp=sqrt(e[mk(stw,sth)]);
	while(1ll*tmp*tmp>e[mk(stw,sth)])tmp--;
	while(1ll*(tmp+1)*(tmp+1)<=e[mk(stw,sth)])tmp++;
	int ans=0;
	rep(i,1,tmp)if(val%i==0){
		i64 res=i;
		if(v1%res==0&&v2%(val/res)==0)ans++;
		if(val/i!=i){
			res=val/i;
			if(v1%res==0&&v2%(val/res)==0)ans++;
		}
	}cout<<ans<<endl;
	return 0;
}