#include<bits/stdc++.h>
using namespace std;

long long n,a[100005],b[100005],c[100005];

void solve(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>c[i];
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];
    long long pa=-1e18,ans=0;
    for(int i=2;i<=n;i++){
        if(a[i]!=b[i]){
            pa-=abs(a[i]-b[i]);
            pa+=c[i]+1;
            pa=max(pa,c[i]+1+abs(a[i]-b[i]));
            ans=max(ans,pa);
        }else{
            ans=max(ans,c[i]+1);
            pa=c[i]+1;
        }
    }
    cout<<ans<<'\n';
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--)solve();

    return 0;
}