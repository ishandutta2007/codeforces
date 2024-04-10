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
typedef pair<pin,int> info;
info a[maxn];int n,m;
int u[maxn],v[maxn];
int main(){
    read(n);read(m);
    rep(i,1,m)read(a[i].w1.w1),read(a[i].w1.w2),a[i].w2=i;
    sort(a+1,a+1+m);
    int cnt=1,pcnt=1;
	rep(i,1,m){
		while(pcnt<=m&&a[pcnt].w1.w2==1)pcnt++;
		if(a[i].w1.w2==0)continue;u[a[i].w2]=cnt;v[a[i].w2]=cnt+1;
		rep(k,1,cnt-1){
			if(pcnt>m)break;
			if(a[pcnt].w1.w1<a[i].w1.w1){
				puts("-1");
				return 0;
			}
			u[a[pcnt].w2]=k;v[a[pcnt].w2]=cnt+1;pcnt++;
			while(pcnt<=m&&a[pcnt].w1.w2==1)pcnt++;
		}cnt++;
	}
    rep(i,1,m)printf("%d %d\n",u[i],v[i]);
	return 0;
}