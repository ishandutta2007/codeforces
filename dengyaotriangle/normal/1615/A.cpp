#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        long long x=0;
        for(int i=0;i<n;i++){
            int z;cin>>z;x+=z;
        }
        cout<<(!!(x%n))<<'\n';
    }
    return 0;
}