#include<bits/stdc++.h>
//dengyaotriangle!
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--){
        long long s,t,n;
        cin>>s>>t>>n;
        long long q=s+t+n;
        long long lb=max(s,(q+2)/2),ub=q-t;
        cout<<max(0ll,ub-lb+1)<<'\n';
    }
    return 0;
}