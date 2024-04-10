#include<bits/stdc++.h>
using namespace std;

int t,n,k;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--){
        cin>>n>>k;
        if(n<=k){
            cout<<k-n<<'\n';
        }else{
            cout<<(n-k&1)<<'\n';
        }
    }

    return 0;
}