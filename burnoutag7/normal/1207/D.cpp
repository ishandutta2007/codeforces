#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod=998244353;

int n;
pair<int,int> a[300005];
ll pw[300005];
ll resa,resb,res;

bool cmp(pair<int,int> a,pair<int,int> b){
    return a.second<b.second;
}

ll bp(ll a,ll n){
    ll res=1;
    while(n>0){
        if(n&1){
            res=res*a%mod;
        }
        n>>=1;
        a=a*a%mod;
    }
    return res;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    resa=resb=res=1;
    pw[0]=1;
    for(int i=1;i<=n;i++){
        cin>>a[i].first>>a[i].second;
        pw[i]=pw[i-1]*i%mod;
    }
    sort(a+1,a+1+n);
    int la=0,lb=0,l=0;
    bool fa=false,fb=false,f=false,com=true;
    for(int i=1;i<=n;i++){
        if(a[i].first==a[i+1].first){//cout<<i<<endl;
            if(!fa){
                fa=true;
                la=i;
            }
        }else{
            if(fa){
                resa=resa*pw[i-la+1]%mod;
                fa=false;
            }
        }
        if(a[i].second>a[i+1].second&&i!=n){
            com=false;
        }
        if(a[i].first==a[i+1].first&&a[i].second==a[i+1].second){//cout<<i<<endl;
            if(!f){
                f=true;
                l=i;
            }
        }else{
            if(f){
                res=res*pw[i-l+1]%mod;
                f=false;
            }
        }
    }
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++){
        if(a[i].second==a[i+1].second){//cout<<i<<endl;
            if(!fb){
                fb=true;
                lb=i;
            }
        }else{
            if(fb){
                resb=resb*pw[i-lb+1]%mod;
                fb=false;
            }
        }
    }
    ll ans=pw[n];
    ans=(ans-resa+mod)%mod;
    ans=(ans-resb+mod)%mod;
    ans=(ans+res*com)%mod;
    cout<<ans<<endl;

    return 0;
}