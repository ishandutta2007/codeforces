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
int ans[105],m,n,x;
int main(){
	// judge();
	read(m);read(n);//read(x);
	rep(i,1,n){
		printf("%d\n",1);
		fflush(stdout);
		read(ans[i]);
		if(ans[i]==0){
			return 0;
		}
	}
	int l=1,r=m;
	rep(i,1,40){
		int md=(l+r)>>1;
		printf("%d\n",md);
		fflush(stdout);
		read(ans[i+n]);
		if(ans[i+n]==0){
			return 0;
		}
		ans[i+n]*=ans[(i-1)%n+1];
		if(ans[i+n]==1){
			l=md+1;
		}else{
			r=md-1;
		}
	}
	return 0;
}