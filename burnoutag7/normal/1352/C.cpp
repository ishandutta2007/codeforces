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
        cout<<k/(n-1)*n+(k%(n-1)?k%(n-1):-1)<<endl;
    }

    return 0;
}