#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    if(n&1){
        cout<<"YES\n";
        for(int i=0;i<n;++i){
            if(i&1)cout<<i*2+2<<' ';
            else cout<<i*2+1<<' ';
        }
        for(int i=0;i<n;++i){
            if(i&1)cout<<i*2+1<<' ';
            else cout<<i*2+2<<' ';
        }
    }
    else{
        cout<<"NO\n";
    }
}