#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define forE(i,x) for(int i=head[x];i!=-1;i=ne[i])
using namespace std;
typedef long long int64;
#define mk(a,b) make_pair(a,b)
#define w1 first
#define w2 second
typedef pair<int,int> pin;
const int maxn=100005;
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
int x[maxn],y[maxn],n,ax,ay,bx,by,tx,ty;
typedef double ld;
#define mk make_pair
pair<ld,int> d1[maxn],d2[maxn],d3[maxn];
#define sqr(x) (1ll*(x)*(x))
int main(){
    read(ax);read(ay);read(bx);read(by);read(tx);read(ty);
    read(n);
    rep(i,1,n)read(x[i]),read(y[i]);
    rep(i,1,n)d1[i]=mk(sqrt(sqr(ax-x[i])+sqr(ay-y[i])),i),d2[i]=mk(sqrt(sqr(bx-x[i])+sqr(by-y[i])),i),d3[i]=mk(sqrt(sqr(tx-x[i])+sqr(ty-y[i])),i);
    rep(i,1,n)d1[i].w1-=d3[i].w1,d2[i].w1-=d3[i].w1;
    if(n==1){
        printf("%.10f\n",min(d1[1].w1,d2[1].w1)+d3[1].w1+d3[1].w1);
        return 0;
    }
    sort(d1+1,d1+1+n);sort(d2+1,d2+1+n);
    ld ans=0;
    rep(i,1,n)ans+=2*d3[i].w1;
    if(d1[1].w2!=d2[1].w2){
    	ans+=min(min(d1[1].w1,d2[1].w1),d1[1].w1+d2[1].w1);
    }else{
    	ans+=min(min(d1[1].w1,d2[1].w1),min(d1[1].w1+d2[2].w1,d1[2].w1+d2[1].w1));
    }
    printf("%.10f\n",ans);
    return 0;
}