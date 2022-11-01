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
i64 n;
int q;
inline i64 solve(i64 n,i64 k){
	if(k%2==1){
		return (k+1)/2;
	}
	i64 pr=(n+1)/2;
	i64 currank=k/2;
	i64 left=n-pr;
	if(n%2==0)
		return solve(left,currank)+pr;
	if(currank==1)currank=left;else currank--;
	return solve(left,currank)+pr;
}
int main(){
	cin>>n>>q;
	while(q--){
		i64 x;scanf("%I64d",&x);
		printf("%I64d\n",solve(n,x));
	}
	return 0;
}