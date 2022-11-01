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
        while(n>=10){
            ans+=n-n%10;
            n=n/10+n%10;
        }
        cout<<ans+n<<endl;
    }

    return 0;
}