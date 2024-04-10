#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b,n;
        cin>>a>>b>>n;
        if(a>b)swap(a,b);
        int ans=0;
        while(b<=n){
            int nb=b+a;
            a=b;b=nb;
            ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}