#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod=1e9+7;

int n,cnt[60],pw[60];
ll a[500005];

void mian(){
    cin>>n;
    memset(cnt,0,sizeof(cnt));
    for(int i=1;i<=n;i++){
        cin>>a[i];
        for(int j=0;j<60;j++){
            if(a[i]>>j&1)cnt[j]++;
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        int an=0,o=0;
        for(int j=0;j<60;j++){
            if(a[i]>>j&1){
                an=(an+(ll)cnt[j]*pw[j])%mod;
                o=(o+(ll)n*pw[j])%mod;
            }else{
                o=(o+(ll)cnt[j]*pw[j])%mod;
            }
        }
        ans=(ans+(ll)an*o)%mod;
    }
    cout<<ans<<'\n';
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    pw[0]=1;
    for(int i=1;i<60;i++)pw[i]=pw[i-1]*2%mod;
    int T;
    cin>>T;
    while(T--)mian();

    return 0;
}