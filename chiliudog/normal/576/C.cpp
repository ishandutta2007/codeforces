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
const int maxn=1000005;
struct Point{
    int x,y,pr;
    inline void in(){read(x);read(y);}
};
inline bool cmpX(const Point &a,const Point &b){
    return a.x<b.x||(a.x==b.x&&a.y<b.y);
}
inline bool cmpY(const Point &a,const Point &b){
    return a.y<b.y||(a.y==b.y&&a.x<b.x);
}
Point a[maxn];
int n;
int main(){
    read(n);rep(i,1,n)a[i].in(),a[i].x/=1024,a[i].pr=i;
    sort(a+1,a+1+n,cmpX);
    i64 dis=0;
    rep(i,1,n-1)dis+=abs(a[i].x-a[i+1].x)+abs(a[i].y-a[i+1].y);
    dis=0;
    if(dis<=2500000000ll){
        rep(i,1,n)printf("%d ",a[i].pr);
        return 0;
    }sort(a+1,a+1+n,cmpY);
    dis=0;
    rep(i,1,n-1)dis+=abs(a[i].x-a[i+1].x)+abs(a[i].y-a[i+1].y);
    if(dis<=2500000000ll){
        rep(i,1,n)printf("%d ",a[i].pr);
        return 0;
    }
    assert(0);
	return 0;
}