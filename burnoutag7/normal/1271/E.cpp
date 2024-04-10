#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n,k;

bool check(ll m){
    ll l=m,r=m,res=0;
    if(!(m&1)){r++;}
    for(int i=1;;i++){
        res+=min(n,r)-l+1;
        //for(int j=l;j<=min(r,n);j++)cerr<<j<<' ';
        l<<=1;
        r=(r<<1)+1;
        if(l>n)break;
        
    }//cerr<<endl;
    return res>=k;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    //for(int i=1;i<=n;i++)check(i);
    ll l=1,r=(n+1)/2,m,ans;
    while(l<=r){
        m=(l+r)>>1;
        if(check(2*m-1)){
            ans=2*m-1;
            l=m+1;
        }else{
            r=m-1;
        }
    }
    l=1;r=n/2;
    while(l<=r){
        m=(l+r)>>1;
        if(check(2*m)){
            ans=max(ans,2*m);
            l=m+1;
        }else{
            r=m-1;
        }
    }
    cout<<ans<<endl;

    return 0;
}