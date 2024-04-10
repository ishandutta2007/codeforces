#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod=1e9+7;

int fact[100005],inv[100005];

ll C(int n,int r){
    return (ll)fact[n]*inv[n-r]%mod*inv[r]%mod;
}

int n,eq,a[100005],l,h;
vector<int> vl,vh;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    fact[0]=inv[0]=fact[1]=inv[1]=1;
    for(int i=2;i<=100000;i++){
        fact[i]=(ll)fact[i-1]*i%mod;
        inv[i]=(ll)(mod-mod/i)*inv[mod%i]%mod;
    }
    for(int i=2;i<=100000;i++){
        inv[i]=(ll)inv[i-1]*inv[i]%mod;
    }

    cin>>n;
    ll sum=0;
    for(int i=1;i<=n;i++)cin>>a[i],sum+=a[i];
    if(sum%n){
        cout<<0;
        return 0;
    }
    sort(a+1,a+1+n);
    eq=sum/n;
    a[0]=-1;
    for(int i=1;i<=n;i++){
        if(a[i]<eq)l=i;
        if(a[i]>eq&&h==0)h=n+1-i;
        if(a[i]<eq){
            if(a[i]==a[i-1])vl.back()++;
            else vl.emplace_back(1);
        }else if(a[i]>eq){
            if(a[i]==a[i-1])vh.back()++;
            else vh.emplace_back(1);
        }
    }
    ll la=fact[l],ha=fact[h],ans=fact[n];
    ans=ans*inv[n-l-h]%mod;
    for(int x:vl)la=la*inv[x]%mod;
    for(int x:vh)ha=ha*inv[x]%mod;
    for(int x:vl)ans=ans*inv[x]%mod;
    for(int x:vh)ans=ans*inv[x]%mod;
    if(l==1||h==1)cout<<ans;
    else if(l+h)cout<<C(n,n-l-h)*la%mod*ha%mod*2%mod;
    else cout<<1;

    return 0;
}