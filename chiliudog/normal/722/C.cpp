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
#define dg(...) fprintf(stderr,__VA_ARGS__);
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
int a[maxn],n;i64 sum[maxn];
int p[maxn];
set<int> del;
typedef set<int>::iterator It;
typedef pair<i64,pin> info;
set<info> res;
inline i64 query(int x,int y){return sum[y]-sum[x-1];}
int main(){
	// judge();
	read(n);rep(i,1,n)read(a[i]);
	rep(i,1,n)read(p[i]);
	rep(i,1,n)sum[i]=sum[i-1]+a[i];
	del.insert(0);del.insert(n+1);
	res.insert(mk(sum[n],mk(1,n)));//cerr<<n;
	rep(i,1,n){
		i64 ans=0;
		del.insert(p[i]);
		It it1=del.find(p[i]);It it2=it1;
		it1--;it2++;
		res.erase(mk(query(*it1+1,*it2-1),mk(*it1+1,*it2-1)));
		res.insert(mk(query(*it1+1,p[i]-1),mk(*it1+1,p[i]-1)));
		res.insert(mk(query(p[i]+1,*it2-1),mk(p[i]+1,*it2-1)));
		ans=max(ans,(*res.rbegin()).w1);
		// cerr<<res.size()<<endl;
		// cerr<<(*res.rbegin()).w1<<endl;
		// cerr<<(*res.rend()).w1<<endl;
		printf("%I64d\n",ans);
	}
	return 0;
}