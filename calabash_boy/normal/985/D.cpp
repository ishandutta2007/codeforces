#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long LL;
LL n,h;
const LL INF = 1e18+100;
inline LL sum(LL x){
    if(x>2e9)return INF;
    return x&1?(x+1)/2*x:x/2*(x+1);
}
int main(){
    cin>>n>>h;
    LL l=h;
    LL r = 2e9;
    if(n<sum(h)){
        LL l=0;
        LL r=h;
        while (r-l>1){
            LL mid =l+r >>1;
            LL cost = sum(mid);
            if(n>=cost){
                l = mid;
            }else{
                r = mid;
            }
        }
        LL ans=0;
        LL maxH =0;
        if(n>=sum(r)){
            n-=sum(r);
            maxH =r;
            ans = r;
        }else{
            n-=sum(l);
            maxH =l;
            ans =l;
        }
        ans+=n/maxH;
        n%=maxH;
        if(n)ans++;
        cout<<ans<<endl;
        return 0;
    }
    while (r-l>1){
        LL mid = l+r >>1;
        LL cost = sum(mid)+sum(mid-1)-sum(h-1);
        if(n>=cost){
            l = mid;
        }else{
            r = mid;
        }
    }
    LL ans=0;
    LL maxH = -1;
    LL costr = sum(r)+sum(r-1)-sum(h-1);
    if(n>=costr){
        ans = r+(r-h);
        maxH=r;
        n-=costr;
    }else{
        LL costl =sum(l)+sum(l-1)-sum(h-1);

        ans = l+(l-h);
        maxH =l;
        n-=costl;
    }
    ans+=n/maxH;
    n%=maxH;
    if(n)ans++;
    cout<<ans<<endl;
    return 0;
}