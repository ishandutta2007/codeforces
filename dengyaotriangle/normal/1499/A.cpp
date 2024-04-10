#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k1,k2,w,b;
        cin>>n>>k1>>k2>>w>>b;
        bool ok=w<=min(k1,k2)+(max(k1,k2)-min(k1,k2))/2;
        k1=n-k1;k2=n-k2;
        ok&=b<=min(k1,k2)+(max(k1,k2)-min(k1,k2))/2;
        cout<<(ok?"YES\n":"NO\n");
    }
    return 0;
}