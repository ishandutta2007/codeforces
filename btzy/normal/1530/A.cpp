#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main(){
    ios_base::sync_with_stdio(false);
    int tc;
    cin>>tc;
    for(int ct=0;ct<tc;++ct){
        int x;
        cin>>x;
        int ans=0;
        while(x>0){
            ans=max(ans,x%10);
            x/=10;
        }
        cout<<ans<<'\n';
    }
}