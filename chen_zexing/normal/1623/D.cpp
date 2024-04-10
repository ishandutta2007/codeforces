#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <climits>
#include <algorithm>
#include <string.h>
using namespace std;
long long mod=1000000007;
long long qpow(long long a,long long b){
    long long ans=1;
    while(b){
        if(b&1) ans=ans*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return ans;
}
int main() {
    int T = 1;
    cin >> T;
    while(T--){
        int n,m,x1,y1,x2,y2,p;
        cin>>n>>m>>x1>>y1>>x2>>y2>>p;
        long long a=1,b=0;
        long long iv100=qpow(100,mod-2);
        int dx=-1,dy=-1,x=x1,y=y1,f=0;
        if(x==1&&dx==-1||x==n&&dx==1) dx=-dx;
        if(y==1&&dy==-1||y==m&&dy==1) dy=-dy;
        int stdx=dx,stdy=dy;
        while(x!=x1||y!=y1||dx!=stdx||dy!=stdy||!f){
            //cout<<x<<" "<<y<<endl;
            x+=dx,y+=dy,f=1;
            if(x==x2||y==y2) a*=1LL*(100-p)*iv100%mod,b*=1LL*(100-p)*iv100%mod,b+=1LL*(100-p)*iv100%mod;
            else b++;
            a%=mod,b%=mod;
            if(x==1&&dx==-1||x==n&&dx==1) dx=-dx;
            if(y==1&&dy==-1||y==m&&dy==1) dy=-dy;
        }
        printf("%lld\n",b*(qpow(1-a+mod,mod-2))%mod);
    }
    return 0;
}