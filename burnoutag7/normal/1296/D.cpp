#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n,a,b,k;
ll h[200005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>a>>b>>k;
    for(ll i=0;i<n;i++){
        cin>>h[i];
        h[i]%=a+b;
        if(h[i]==0)h[i]+=a+b;
        h[i]=(h[i]-1)/a;
    }
    sort(h,h+n);
    ll ans=0;
    for(int i=0;i<n;i++){
        k-=h[i];
        if(k>=0)ans++;
        else break;
    }
    cout<<ans<<endl;

    return 0;
}