#include<bits/stdc++.h>
using namespace std;

int n,a[105],mn,ans;

void solve(){
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    mn=*min_element(a,a+n);
    ans=0;
    for(int i=0;i<n;i++)ans+=mn<a[i];
    cout<<ans<<'\n';
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)solve();

    return 0;
}