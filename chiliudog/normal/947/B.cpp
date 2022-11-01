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
int n;
i64 v[maxn],t[maxn],tot;
multiset<i64> zb;
int main(){
	read(n);
	rep(i,1,n)scanf("%I64d",&v[i]);
	rep(i,1,n)scanf("%I64d",&t[i]);
	rep(i,1,n){
		zb.insert(v[i]+tot);
		i64 res=0;
		while(zb.size()){
			if(*zb.begin()>tot+t[i])break;
			res+=(*zb.begin()-tot);
			zb.erase(zb.begin());
		}
		tot+=t[i];
		res+=1ll*(zb.size())*t[i];
		printf("%I64d ",res);
	}
	return 0;
}