#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
using namespace std;
const int MAXN=3e5+10;
const long double EPS=1e-9;
bool eq(const ldb& d1,const ldb& d2){
    return d1==d2;
    //return fabs(d1-d2)<EPS;
}
bool gt(const ldb& d1,const ldb& d2){
    return d1>d2;
    //return d1-d2>EPS;
}
bool lt(const ldb& d1,const ldb& d2){
    return d1<d2;
    //return d2-d1>EPS;
}
ll T,n,a,b,p[MAXN],q[MAXN];
ldb len,sx,sy,ex,ey;
struct Line{
    ldb k,len,idx,dx,dy;
    bool operator<(const Line& l2)const{
        if(dx*l2.dy != l2.dx*dy)return dx*l2.dy > l2.dx*dy;
        else return idx<l2.idx;
    }
};
set<Line>convex;
void exc(){
    //
    while(sx<0){
        Line line=*convex.begin();
        convex.erase(line);

        ldb xdis=line.len,k=line.k;
        
        if(gt(-sx,xdis)){
            sx+=xdis;
            sy+=xdis*k;
            continue;
        }

        sy+=(-sx)*k;
        line.len-=(-sx);
        sx=0;
        convex.insert(line);
        break;
    }
    //
    while(ey<0){
        Line line=*convex.rbegin();
        convex.erase(line);

        ldb xdis=line.len,k=line.k,ydis=-line.dx*xdis/line.dy;

        if(gt(-ey,ydis)){
            ex-=xdis;
            ey+=ydis;
            continue;
        }

        ex+=(-ey)*line.dy/line.dx;
        line.len-=ey*line.dy/line.dx;
        ey=0;
        convex.insert(line);

        break;
    }
}
void solve(){
    scanf("%d%d%d",&n,&a,&b);
    rep(i,1,n)scanf("%d",&p[i]);
    rep(i,1,n)scanf("%d",&q[i]);
    convex.clear();
    len=0;sx=sy=ex=ey=0;

    sx=a-p[1];sy=b+q[1];
    ex=a+p[1];ey=b-q[1];
    len=2*p[1];
    convex.insert((Line){(ldb)-q[1]/p[1],2*p[1],1,-q[1],p[1]});

    exc();

    printf("%.6Lf\n",ex);
    
    rep(i,2,n){
        ldb k=(*convex.rbegin()).k;
        ldb nk=(ldb)-q[i]/p[i];
        convex.insert((Line){(ldb)-q[i]/p[i],2*p[i],i,-q[i],p[i]});
        ldb pk=(*convex.begin()).k;
        sx-=p[i],sy+=q[i];
        
        ex+=p[i],ey-=q[i];

        exc();
        printf("%.6Lf\n",ex);
    }

}
int main(){
    scanf("%d",&T);
    while(T--)solve();


    return 0;
}