#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll T,n,r;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>T;
    while(T--){
        cin>>n>>r;
        if(r>=n){
            cout<<n*(n-1)/2+1<<endl;
        }else{
            cout<<r*(r+1)/2<<endl;
        }
    }

    return 0;
}