#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod=1e9+7;

int n,a[200005],ans,tmp;
map<ll,int> f;
ll p;

void mian(){
    cin>>n;
    f.clear();
    f[0]=ans=1;
    p=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        p+=a[i-1];
        tmp=f[p];
        f[p]=ans;
        ans=(ans*2ll-tmp+mod)%mod;
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