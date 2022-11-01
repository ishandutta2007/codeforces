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
const int maxn=1005;
int a[maxn],b[maxn];
int m,n;
typedef double ld;
inline bool check(ld md){
	ld res=md;
	res-=(res+m)/a[1];
	rep(i,2,n){
		if(res<0)return 0;
		res-=(res+m)/b[i];
		if(res<0)return 0;
		res-=(res+m)/a[i];
		if(res<0)return 0;
	}
	res-=(res+m)/b[1];
	if(res<0)return 0;
	return 1;
}
int main(){
	read(n);read(m);
	rep(i,1,n)read(a[i]);
	rep(i,1,n)read(b[i]);
	int ts=100;
	if(!check(1e10)){
		puts("-1");return 0;
	}
	ld l=0,r=1e9;
	while(ts--){
		ld md=(l+r)/2;
		if(check(md)){
			r=md;
		}else{
			l=md;
		}
	}
	printf("%.10f\n",l);
	return 0;
}