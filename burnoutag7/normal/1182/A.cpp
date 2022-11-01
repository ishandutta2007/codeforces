#include<bits/stdc++.h>
using namespace std;

int n;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    if(n%2){
        cout<<0<<endl;
        return 0;
    }
    long long ans=1;
    for(int i=1;i*2<=n;i++){
        ans*=2;
    }
    cout<<ans<<endl;

    return 0;
}