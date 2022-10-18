#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!


int main(){
    int t;cin>>t;
    while(t--){
        long long x;cin>>x;
        if(x%14>6||x%14<1||x<14)cout<<"NO\n";
        else cout<<"YES\n";
    }
    return 0;
}