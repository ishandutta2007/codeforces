#include <bits/stdc++.h>
using namespace std;

int n,m;
int main(){
    //
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    if (m&1) cout<<(m+1)/2;
    else {
        n/=2;
        m/=2;
        cout<<n-m+1;
    }
}