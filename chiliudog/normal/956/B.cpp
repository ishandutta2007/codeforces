#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<cstring>
#include<vector>
#include<map>
#include<cassert>
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
const int maxn=1e5+5;
int n,U;
int E[maxn],Q[maxn];
typedef long double ld;
inline bool check(ld v){
	int front=0,finish=0;
	int k=0;
	rep(i,1,n){
		while(k<n&&E[k+1]-E[i]<=U){
			k++;
			while(front<finish&&E[k]>=E[Q[finish]])finish--;
			Q[++finish]=k;
		}
		while(front<finish&&Q[front+1]<i+2)front++;
		if(front<finish&&((1-v)*E[Q[front+1]]+v*E[i]-E[i+1]>=0))return 1;
	}
	return 0;
}
int main(){
	read(n);read(U);
	rep(i,1,n)read(E[i]);
	ld l=0,r=1,ans=0;
	int flag=0;
	rep(T,1,60){
		ld m=(l+r)/2;
		if(check(m))flag=1,ans=m,l=m;
		else r=m;
	}
	if(!flag)puts("-1");
	else printf("%.10f\n",(double)ans);
	return 0;
}