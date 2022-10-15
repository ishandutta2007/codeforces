#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll sum,h_max;
ll r=0,pas=(1LL<<30);

ll gauss(ll st,ll dr){
    if(st>dr)
        return 0;
    ll dif=dr-st+1;
    return dif*st+dif*(dif-1)/2;
}

ll r2=0;

ll solution=0;

ll nxt(ll x,ll sm){
    ll add=x*(x-1)/2;
    return (sm-add);
}

ll rep(ll x,ll sm){
    ll adun=x*(x-1)/2;
    sm-=adun;
    return sm/x;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>sum>>h_max;
    while(pas){
        ll val=r+pas;
        if(val<=h_max && gauss(1,val)<=sum)
            r+=pas;
        pas/=2;
    }
    pas=(1LL<<30);
    while(pas){
        ll val=r2+pas;
        if(gauss(r,val-1)+gauss(1,val)<=sum)
            r2+=pas;
        pas/=2;
    }
    sum-=gauss(r,r2-1);
    solution=(r2-r)+r2;
    r=r2;
    while(r>0){
        ll cate=rep(r,sum);
        solution+=(cate-1);
        sum-=(cate*r);
        ll cine=nxt(r,sum);
        sum-=gauss(cine+1,r-1);
        r=cine;
    }
    if(sum!=0){
        cout<<"ERROR\n";
    }
    else{
        cout<<solution<<"\n";
    }
    return 0;
}
/**



**/