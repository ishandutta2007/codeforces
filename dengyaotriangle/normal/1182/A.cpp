#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    int n;
    cin>>n;
    if(n&1){
        cout<<0;
        return 0;
    }
    long long ans=1;
    n/=2;
    while(n--)ans*=2;
    cout<<ans;
    return 0;
}