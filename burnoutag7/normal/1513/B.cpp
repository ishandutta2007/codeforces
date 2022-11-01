#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod=1e9+7;

int n,a[200005];

void mian(){
    cin>>n;
    ll m=1;
    int g=-1;
    for(int i=1;i<=n;i++)cin>>a[i],g&=a[i];
    for(int i=1;i<=n-2;i++)m=m*i%mod;
    int c=0;
    for(int i=1;i<=n;i++)c+=a[i]==g;
    cout<<(ll)c*(c-1)%mod*m%mod<<'\n';
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