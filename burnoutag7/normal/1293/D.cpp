#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll xz,yz,ax,ay,bx,by,xs,ys,t;

inline ll px(ll cx){
    return (cx-bx)/ax;
}

inline ll py(ll cy){
    return (cy-by)/ay;
}

inline ll nx(ll cx){
    return ax*cx+bx;
}

inline ll ny(ll cy){
    return ay*cy+by;
}

inline ll dis(ll xl,ll yl,ll xr,ll yr){
    return abs(xl-xr)+abs(yl-yr);
}

ll up_first(){
    ll xl,yl,xr,yr,cnt=1,res=0;
    xl=xz;
    yl=yz;
    while(dis(xl,yl,xs,ys)>dis(nx(xl),ny(yl),xs,ys)){
        xl=nx(xl);yl=ny(yl);
    }
    xr=xl;yr=yl;
    while(dis(xr,yr,xs,ys)<=t){
        while(dis(xr,yr,xs,ys)+dis(xl,yl,xr,yr)>t){
            xl=nx(xl);
            yl=ny(yl);
            cnt--;
        }
        while(px(xl)>=xz&&dis(xr,yr,xs,ys)+dis(px(xl),py(yl),xr,yr)<=t){
            xl=px(xl);
            yl=py(yl);
            cnt++;
        }
        res=max(res,cnt);
        xr=nx(xr);
        yr=ny(yr);
        cnt++;
    }
    return res;
}

ll down_first(){
    ll xl,yl,xr,yr,cnt=1,res=0;
    xl=xz;
    yl=yz;
    while(dis(xl,yl,xs,ys)>=dis(nx(xl),ny(yl),xs,ys)){
        xl=nx(xl);yl=ny(yl);
    }
    xr=xl;yr=yl;
    while(xl>=xz&&dis(xl,yl,xs,ys)<=t){
        while(dis(xl,yl,xs,ys)+dis(xl,yl,xr,yr)>t){
            xr=px(xr);
            yr=py(yr);
            cnt--;
        }
        while(dis(xl,yl,xs,ys)+dis(xl,yl,nx(xr),ny(yr))<=t){
            xr=nx(xr);
            yr=ny(yr);
            cnt++;
        }
        res=max(res,cnt);
        xl=px(xl);
        yl=py(yl);
        cnt++;
    }
    return res;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>xz>>yz>>ax>>ay>>bx>>by>>xs>>ys>>t;
    cout<<max(up_first(),down_first())<<endl;

    return 0;
}