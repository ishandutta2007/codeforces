#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,a[200005];

void mian(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    ll ans=0;
    for(int i=n-1;i>=1;i--){
        ans+=max(0,a[i]-a[i+1]);
    }
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