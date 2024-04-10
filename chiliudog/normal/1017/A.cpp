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
inline bool cmp(pin a,pin b){
	return a.w1>b.w1||(a.w1==b.w1&&a.w2<b.w2);
}
const int maxn=10005;
pin a[maxn];
int main(){
	int n;
	read(n);
	rep(i,1,n){
		int res=0;int x;
		rep(j,1,4){
			read(x);
			res+=x;
		}
		a[i]=mk(res,i);
	}sort(a+1,a+1+n,cmp);
	// rep(i,1,n){
		// printf("%d %d\n",a[i].w1,a[i].w2);
	// }
	rep(i,1,n){
		if(a[i].w2==1){
			printf("%d\n",i);
			return 0;
		}
	}
	return 0;

}