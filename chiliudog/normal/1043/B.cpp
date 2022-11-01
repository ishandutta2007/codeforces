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
int a[maxn],x[maxn],n,k;
i64 sum[maxn];
int main(){
	read(n);
	rep(i,1,n){
		read(a[i]);
	}vector<int> ans;
	rep(k,1,n){
		rep(i,0,k-1)x[i]=a[i+1]-a[i];
		bool flag=1;
		rep(i,1,n){
			sum[i]=sum[i-1]+x[(i-1)%k];
			if(sum[i]!=a[i]){
				flag=0;break;
			}
		}if(flag)ans.pb(k);
	}
	printf("%d\n",ans.size());
	for(int x:ans){
		printf("%d ",x);
	}
	return 0;
}