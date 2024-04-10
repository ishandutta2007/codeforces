#include<bits/stdc++.h>
using namespace std;

int t,a1,b1,a2,b2;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--){
        cin>>a1>>b1>>a2>>b2;
        if(a1==a2&&b1+b2==a1){
            cout<<"Yes\n";
        }else
        if(a1==b2&&a2+b1==a1){
            cout<<"Yes\n";
        }else
        if(b1==a2&&a1+b2==b1){
            cout<<"Yes\n";
        }else
        if(b1==b2&&a1+a2==b1){
            cout<<"Yes\n";
        }else cout<<"No\n";
    }

    return 0;
}