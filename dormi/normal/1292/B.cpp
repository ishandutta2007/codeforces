#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
void sc(){}
template<typename T,typename... Args>
void sc(T& a, Args&... args) {cin>>a,sc(args...);}
template<typename T>
void pr(T a){cout<<a;}
template<typename T,typename... Args>
void pr(T a, Args... args) {cout<<a<<" ",pr(args...);}
template<typename T>
void prl(T a){cout<<a<<"\n";}
template<typename T,typename... Args>
void prl(T a, Args... args) {cout<<a<<" ",prl(args...);}
template<typename T>
int sz(const T &a){return (int)a.size();}
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
lli x0,ree,ax,ay,bx,by,xs,ys,t;
bool overflow(lli xc,lli yc){
    return (LLONG_MAX-by)/ay<=yc||(LLONG_MAX-bx)/ax<=xc;
}
lli dist(lli x,lli y,lli xc,lli yc){
    return abs(x-xc)+abs(y-yc);
}
lli test(lli xc,lli yc){
    lli need=abs(xs-xc)+abs(ys-yc);
    if(need>t)return 0;
    lli tet=t-need;
    lli am=1;
    lli x=xc,y=yc;
    lli ans=1;
    while(x!=x0){
        if(tet>=dist(x,y,xc,yc)){
            lli tex=xc,tey=yc;
            lli team=0;
            while(!overflow(tex,tey)){
                tex=tex*ax+bx,tey=tey*ay+by;
                if(dist(x,y,xc,yc)+dist(x,y,tex,tey)>tet)break;
                team++;
            }
            ans=max(ans,am+team);
        }
        else break;
        x=(x-bx)/ax,y=(y-by)/ay;
        am++;
    }
    if(x==x0){
        if(tet>=dist(x,y,xc,yc)){
            lli tex=xc,tey=yc;
            lli team=0;
            while(!overflow(tex,tey)){
                tex=tex*ax+bx,tey=tey*ay+by;
                if(dist(x,y,xc,yc)+dist(x,y,tex,tey)>tet)break;
                team++;
            }
            ans=max(ans,am+team);
        }
    }
    return ans;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    sc(x0,ree,ax,ay,bx,by,xs,ys,t);
    lli shortest=LLONG_MAX,xb=-1,yb=-1;
    lli xc=x0,yc=ree;
    while(1){
        if(overflow(xc,yc))break;
        if(abs(xs-xc)+abs(ys-yc)<shortest){
            shortest=abs(xs-xc)+abs(ys-yc);
            xb=xc,yb=yc;
        }
        xc=ax*xc+bx,yc=ay*yc+by;
    }
    lli ans=0;
    ans=max(ans,test(xb,yb));
    lli tebx=xb,teby=yb;
    while(xb!=x0){
        xb=(xb-bx)/ax,yb=(yb-by)/ay;
        ans=max(ans,test(xb,yb));
    }
    xb=tebx,yb=teby;
    while(!overflow(xb,yb)){
        xb=xb*ax+bx,yb=yb*ay+by;
        if(!overflow(xb,yb))ans=max(ans,test(xb,yb));
    }
    prl(ans);
    return 0;
}