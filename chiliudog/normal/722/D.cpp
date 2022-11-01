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
const int maxn=50005;
set<int> used;
int n,a[maxn];
inline bool check(int x){
	used.clear();
	rep(i,1,n){
		int v=a[i];bool flag=0;
		while(v){
			if(v<=x){
				if(!used.count(v)){used.insert(v);flag=1;break;}
			}v/=2;
		}
		if(!flag)return 0;
	}return 1;
}
int main(){
	read(n);rep(i,1,n)read(a[i]);
	int l=n,r=1e9,ans;
	while(l<=r){
		int md=(l+r)>>1;
		if(check(md)){
			ans=md;r=md-1;
		}else l=md+1;
	}check(ans);
	for(auto x:used)printf("%d ",x);
	return 0;
}