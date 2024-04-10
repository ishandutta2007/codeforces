#include<bits/stdc++.h>
using namespace std;

int n,m,ans=1;
int a[1005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    if(n>m){
        cout<<0<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
        for(int j=1;j<i;j++){
            ans=ans*(abs(a[i]-a[j])%m)%m;
        }
    }
    cout<<ans<<endl;

    return 0;
}