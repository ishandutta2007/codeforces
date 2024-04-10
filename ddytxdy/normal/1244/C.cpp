#include<bits/stdc++.h>
#define LL long long
using namespace std;
LL n,p,w,d,x,y;
LL exgcd(LL a,LL b,LL &x,LL &y){
    if(!b){x=1;y=0;return a;}
    LL g=exgcd(b,a%b,y,x);
    y-=a/b*x;return g;
}
int main(){
    cin>>n>>p>>w>>d;
    LL g=exgcd(w,d,x,y);
    for(int i=0;i<w/g;i++){
        if((p-i*d)%w==0){
            x=(p-i*d)/w;
            if(x>=0&&x+i<=n)cout<<x<<" "<<i<<" "<<n-x-i<<endl;
            else puts("-1");
            exit(0);
        }
    }
    puts("-1");
    // LL g=exgcd(w,d,x,y);
    // if(p%g)puts("-1"),exit(0);
    // x*=p/g;y*=p/g;
    // printf("%d %d\n",x,y);
    // y%=w/g;if(y<0)y+=w/g;
    // x=(p-y*d)/w;
    // if(x>=0&&x+y<=n)cout<<x<<" "<<y<<" "<<n-x-y;
    // else puts("-1");
    return 0;
}