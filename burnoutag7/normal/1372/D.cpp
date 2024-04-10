#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,a[200005];
ll ans,pre[200005],suf[200005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(i&1^1)ans+=a[i];
        pre[i]=i>=2?pre[i-2]+a[i]:a[i];
    }
    for(int i=n-1;i>=0;i--){
        suf[i]=suf[i+2]+a[i];
    }
    for(int i=0;i+1<n;i++){
        ans=max(ans,pre[i]+suf[i+1]);
    }
    cout<<ans<<endl;

    return 0;
}