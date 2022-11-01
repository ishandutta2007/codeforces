#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod=998244353;

int n,k,prv;
int p[200005];
ll ans=1,sum;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>p[i];
        if(p[i]>n-k){
            if(prv)ans=ans*(i-prv)%mod;
            prv=i;
            sum+=p[i];
        }
    }
    cout<<sum<<' '<<ans<<endl;

    return 0;
}