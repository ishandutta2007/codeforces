#include<bits/stdc++.h>
using namespace std;

typedef long double ld;
const ld eps=1e-15;

ld dist(ld x1,ld y1,ld x2,ld y2){
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

vector<pair<ld,ld>> intersect(ld x,ld y,ld r,ld R){
    vector<pair<ld,ld>> v;
    ld d=sqrt(x*x+y*y);
    if(d>=R+r-eps){
        if(d<=R+r+eps){
            v.emplace_back(x/(R+r)*R,y/(R+r)*R);
        }
        return v;
    }
    if(d<=abs(R-r)+eps){
        if(d>=abs(R-r)-eps){
            v.emplace_back(x/(R-r)*R,y/(R-r)*R);
        }
        return v;
    }
    ld ad=(R*R+x*x+y*y-r*r)/2,asd=(R*R+x*x+y*y-r*r)/2/(x*x+y*y);
    ld h=sqrt(R*R-ad*ad/(x*x+y*y));
    ld xm=asd*x,ym=asd*y;
    v.emplace_back(xm+h*y/d,ym-h*x/d);
    v.emplace_back(xm-h*y/d,ym+h*x/d);
    return v;
}

bool incl(ld x,ld y,ld r,ld R){
    ld d=sqrt(x*x+y*y);
    return d+R<=r+eps;
}

int t1,t2,xc,yc,xh,yh,xs,ys;
ld d1,d2,d3;

bool check(ld dc){
    ld ds=d1+t1-dc,dh=d3+t2-dc;
    if(ds<=eps||dh<=eps)return false;
    if(incl(xh-xs,yh-ys,dh,ds)&&incl(xc-xs,yc-ys,dc,ds)
     ||incl(xh-xc,yh-yc,dh,dc)&&incl(xs-xc,ys-yc,ds,dc)
     ||incl(xc-xh,yc-yh,dc,dh)&&incl(xs-xh,ys-yh,ds,dh))return true;
    auto v=intersect(xh-xs,yh-ys,dh,ds);
    for(auto &[x,y]:v){
        x+=xs;y+=ys;
        if(dist(x,y,xc,yc)<=dc+eps)return true;
    }
    v=intersect(xh-xc,yh-yc,dh,dc);
    for(auto &[x,y]:v){
        x+=xc;y+=yc;
        if(dist(x,y,xs,ys)<=ds+eps)return true;
    }
    v=intersect(xc-xs,yc-ys,dc,ds);
    for(auto &[x,y]:v){
        x+=xs;y+=ys;
        if(dist(x,y,xh,yh)<=dh+eps)return true;
    }
    return false;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>t1>>t2>>xc>>yc>>xh>>yh>>xs>>ys;
    d1=dist(xc,yc,xs,ys),d2=dist(xs,ys,xh,yh),d3=dist(xc,yc,xh,yh);
    if(d1+d2<=d3+t2+eps){
        cout<<fixed<<setprecision(10)<<min(d3+t2-d1-d2,(ld)t1)+d1+d2<<'\n';
        return 0;
    }
    ld l=0,r=min(d1+d2+t1,d3+t2);
    for(int _=0;_<120;_++){
        ld dc=(l+r)/2;
        (check(dc)?l:r)=dc;
    }
    cout<<fixed<<setprecision(10)<<l<<'\n';

    return 0;
}