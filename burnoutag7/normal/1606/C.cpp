#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void mian(){
    int n;
    ll k,a[10];
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
        ll b=1;
        while(a[i]--)b*=10;
        a[i]=b;
    }
    ll ans=0;
    k++;
    for(int i=0;i+1<n&&k;i++){
        ans+=min(a[i+1]/a[i]-1,k)*a[i];
        k-=min(a[i+1]/a[i]-1,k);
    }
    ans+=k*a[n-1];
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