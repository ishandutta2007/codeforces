#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll t,n;
ll a[100005];
ll pre[100005],suf[100005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--){
        cin>>n;
        for(ll i=1;i<=n;i++){
            cin>>a[i];
            pre[i]=pre[i-1]+a[i];
        }
        suf[n+1]=0;
        for(ll i=n;i>=1;i--){
            suf[i]=suf[i+1]+a[i];
        }
        bool f=true;
        for(ll i=1;i<=n;i++){
            if(suf[i]<=0||pre[i]<=0){
                f=false;
                break;
            }
        }
        if(f){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }

    return 0;
}