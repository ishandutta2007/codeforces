#include<bits/stdc++.h>
using namespace std;

int t,a[3];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--){
        cin>>a[0]>>a[1]>>a[2];
        int ans=0;
        sort(a,a+3);
        ans+=a[1]-a[0];
        a[2]-=a[1]-a[0];
        a[1]-=a[1]-a[0];
        int tmp=min(a[0]+a[1],a[2]);
        ans+=tmp;
        ans+=max(0,a[0]+a[1]-tmp)/2;
        cout<<ans<<endl;
    }

    return 0;
}