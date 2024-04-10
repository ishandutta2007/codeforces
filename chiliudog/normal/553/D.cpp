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
int a[maxn],b[maxn],d[maxn],cur[maxn];
vector<int> son[maxn];
int Queue[maxn],front,finish,nd[maxn],n,m;
int fk[maxn],k;
bool del[maxn];
typedef double ld;
inline bool check(ld md){
	rep(i,1,n)nd[i]=floor(d[i]*md+0.999999999),cur[i]=d[i];
	front=0,finish=k;memset(del,0,sizeof(del));
	rep(i,1,k)Queue[i]=fk[i],del[fk[i]]=1;
	while(front!=finish){
		int x=Queue[++front];
		for(int v:son[x])if(!del[v]){
			cur[v]--;if(cur[v]<nd[v]){
				del[v]=1;Queue[++finish]=v;
			}
		}
	}if(finish==n)return 0;
	return 1;
}
int main(){
 //   judge();
    read(n);read(m);read(k);rep(i,1,k)read(fk[i]);
    rep(i,1,m)read(a[i]),read(b[i]),d[a[i]]++,d[b[i]]++,son[a[i]].pb(b[i]),son[b[i]].pb(a[i]);
    ld l=0,r=1;
    while(r-l>1e-8){
    	ld md=(r+l)/2;
    	if(check(md))
    		l=md;
    	else
    		r=md;
    }check(l);
    int tot=0;
    rep(i,1,n)if(!del[i])tot++;
    if(tot==0){
    	check(0);
	    rep(i,1,n)if(!del[i])tot++;
	}
    printf("%d\n",tot);
    rep(i,1,n)if(!del[i])printf("%d ",i);
    return 0;
}