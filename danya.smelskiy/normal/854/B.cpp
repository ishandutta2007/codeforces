#include <bits/stdc++.h>
using namespace std;

int n,k;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    if (n==k || k==0) cout<<"0 ";
    else cout<<"1 ";
    if (k==0) {
        cout<<"0";
        return 0;
    }
    if (k>=(n+2)/3) {
        cout<<n-k;
        return 0;
    }
    cout<<k*2;
}