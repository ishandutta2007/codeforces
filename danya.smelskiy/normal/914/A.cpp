#include <bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    long long ans=-1e9;
    for (int i=1;i<=n;++i) {
        long long x;
        cin>>x;
        long long y;
        y=(sqrt(x));
        if (y*y!=x) {
            ans=max(ans,x);
        }
    }
    cout<<ans;
}