#include <bits/stdc++.h>
using namespace std;

int n,k;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    if (n==k) {
        cout<<"-1";
        return 0;
    }
    cout<<n-k<<" ";
    int last=0;
    for (int i=2;i<=n;++i) {
        ++last;
        if (last==n-k) ++last;
        cout<<last<<" ";
    }
}