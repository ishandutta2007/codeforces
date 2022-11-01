#include<bits/stdc++.h>
using namespace std;

int t,n,ans;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--){
        cin>>n;
        ans=0;
        for(int i=1;i<=n;i++){
            if(i<n>>1||i==n)ans+=1<<i;
            else ans-=1<<i;
        }
        cout<<ans<<endl;
    }

    return 0;
}