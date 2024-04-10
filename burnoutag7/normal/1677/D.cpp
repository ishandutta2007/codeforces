#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod=998244353;

void mian(){
    int n,k;
    cin>>n>>k;
    int ans=1;
    for(int i=1;i<=k;i++)ans=(ll)ans*i%mod;
    for(int i=k+1;i<=n;i++){
        int v;
        cin>>v;
        if(v==-1)ans=(ll)ans*i%mod;
        if(!v)ans=(ll)ans*(k+1)%mod;
    }
    for(int i=1;i<=k;i++){
        int v;
        cin>>v;
        if(v>0)ans=0;
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