#include<bits/stdc++.h>
using namespace std;

int n,k;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--){
        cin>>n>>k;
        k*=(n+k-1)/k;
        cout<<k/n+(bool)(k%n)<<'\n';
    }

    return 0;
}