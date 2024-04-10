#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod=998244353;

int n;
string a[100005];
ll ext[100005];
ll ans;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        for(int j=0;j<a[i].size();j++){
            ext[i]*=100;
            ext[i]+=(a[i][j]-'0');
            ext[i]%=mod;
        }
    }
    for(int i=1;i<=n;i++){
        ans+=ext[i]*10*n;
        ans%=mod;
        ans+=ext[i]*n;
        ans%=mod;
    }
    cout<<ans<<endl;

    return 0;
}