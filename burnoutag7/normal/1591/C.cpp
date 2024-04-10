#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

pair<ll,int> sola(int n,int k,int *a){
    ll s=0;
    int mx=0;
    for(int i=1;i<=n;i+=k){
        int j=min(n,i+k-1);
        s+=2*a[j];
        mx=max(mx,a[j]);
    }
    return {s,mx};
}

pair<ll,int> solb(int n,int k,int *a){
    ll s=0;
    int mx=0;
    for(int i=n;i>=1;i-=k){
        s+=2*a[i];
        mx=max(mx,a[i]);
    }
    return {s,mx};
}

int n,k,x[200005];

void mian(){
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>x[i];
    sort(x+1,x+1+n);
    int gn=0,mxn=0,mxp=0;
    while(x[gn+1]<0)gn++;
    reverse(x+1,x+gn+1);
    for(int i=1;i<=gn;i++)x[i]=-x[i];
    pair<ll,int> p1[2]={sola(gn,k,x),solb(gn,k,x)},p2[2]={sola(n-gn,k,x+gn),solb(n-gn,k,x+gn)};
    ll ans=1e18;
    for(int i=0;i<2;i++)for(int j=0;j<2;j++)ans=min(ans,p1[i].first+p2[j].first-max(p1[i].second,p2[j].second));
    cout<<ans<<'\n';
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--)mian();

    return 0;
}