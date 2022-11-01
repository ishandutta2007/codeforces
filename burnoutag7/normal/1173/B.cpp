#include<bits/stdc++.h>
using namespace std;

int n;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    cout<<n/2+1<<endl;
    for(int i=1;i<=(n+1)/2;i++){
        cout<<1<<' '<<i<<endl;
    }
    for(int i=(n+1)/2+1;i<=n;i++){
        cout<<i-(n+1)/2+1<<' '<<n/2+1<<endl;
    }

    return 0;
}