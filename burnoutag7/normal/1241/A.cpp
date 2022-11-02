#include<bits/stdc++.h>
using namespace std;

int n,q;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>q;
    while(q--){
        cin>>n;
        if(n==2){
            cout<<2<<endl;
        }else{
            cout<<(n&1)<<endl;
        }
    }

    return 0;
}