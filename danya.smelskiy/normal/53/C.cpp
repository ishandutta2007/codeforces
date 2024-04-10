#include <bits/stdc++.h>
using namespace std;

int n;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    if (n==1) {
        cout<<1;
        return 0;
    }
    int l=(n+1)/2;
    int r=l+1;
    cout<<l<<" "<<r<<" ";
    --l;
    ++r;
    while (l>0) {
        cout<<l<<" ";
        if (r<=n) cout<<r<<" ";
        --l; ++r;
    }
}