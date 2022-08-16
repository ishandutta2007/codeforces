#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define M 1000000007
#define fr first
#define sc second
#define vc vector
#define r0 return 0
ll check(ll h,ll w){
    double a=log(h)/log(2),b=log(w)/log(2),c=pow(2,a),d=pow(2,b),e=1.0*h/w;
    if(c!=h&&d!=w)return 0;
    if(e<0.8||e>1.25)return 0;
    return 1;
}
ll ch(ll h,ll w){
    double e=1.0*h/w;
    if(10*h<8*w)return -1;
    if(4*h>5*w)return 1;
    return 0;
}
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll h,w,x,y;
    pair<ll,pair<ll,ll> > u,v;
    cin>>h>>w;
    if(check(h,w)){cout<<h<<" "<<w;return 0;}

    ll a=log(h)/log(2),b=pow(2,a),c=w,d=ch(b,c);
    while(d==1){
        a--;
        b=pow(2,a);
        d=ch(b,c);
    }
    if(d==-1){
        c=10*b/8;
    }
    u={b*c,{b,c}};

    a=log(w)/log(2);c=pow(2,a);b=h;d=ch(b,c);
    while(d==-1){
        a--;
        c=pow(2,a);
        d=ch(b,c);
    }
    if(d==1){
        b=c*5/4;
    }
    v={b*c,{b,c}};
    if(u>v){
        v=u;
    }
    cout<<v.sc.fr<<" "<<v.sc.sc;
}