#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    ios_base::sync_with_stdio(false);
    int tc;
    cin>>tc;
    for(int ct=0;ct<tc;++ct){
        int n;
        cin>>n;
        for(int i=0;i<n;++i){
            int _;
            cin>>_;
        }
        cout<<n*3<<'\n';
        for(int i=0;i<n;i+=2){
            cout<<2<<' '<<(i+1)<<' '<<(i+2)<<'\n';
            cout<<1<<' '<<(i+1)<<' '<<(i+2)<<'\n';
            cout<<2<<' '<<(i+1)<<' '<<(i+2)<<'\n';
            cout<<2<<' '<<(i+1)<<' '<<(i+2)<<'\n';
            cout<<1<<' '<<(i+1)<<' '<<(i+2)<<'\n';
            cout<<2<<' '<<(i+1)<<' '<<(i+2)<<'\n';
        }
    }
}