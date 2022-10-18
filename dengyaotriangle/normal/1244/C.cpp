#include<bits/stdc++.h>
//dengyaotriangle!
using namespace std;

long long exgcd(long long a,long long b,long long &x,long long &y){
    if(b==0){
        x=1;y=0;return a;
    }
    long long ans=exgcd(b,a%b,y,x);
    y-=(a/b)*x;
    return ans;
}

long long mul(long long a,long long b,long long md){
    if(b==0)return 0;
    long long ans=mul(a,b>>1,md);ans=(ans+ans)%md;
    if(b&1)ans=(ans+a)%md;
    return ans;
}
int main(){
    long long n,p,d,w,x,y,g;
    cin>>n>>p>>w>>d;
    g=exgcd(w,d,x,y);
    assert(w*x+d*y==g);
    if(p%g){
        cout<<-1;
        return 0;
    }
    p/=g;w/=g;d/=g;
    long long mx=mul(((x%d)+d)%d,p,d),my=(p-mx*w)/d;
    if(mx+my<=n&&my>=0){
        cout<<mx<<' '<<my<<' '<<n-mx-my;
        return 0;
    }
    long long iy=mul(((y%w)+w)%w,p,w),ix=(p-iy*d)/w;
    if(ix+iy<=n&&ix>=0){
        cout<<ix<<' '<<iy<<' '<<n-ix-iy;
        return 0;
    }
    cout<<-1;
    return 0;
}