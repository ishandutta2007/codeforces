#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long ans,q;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    m=min(n,m);
    if (n==m || n==m+1) {
        cout<<n;
        return 0;
    }
    ans=m;
    q=m+1;
    long long l=0;
    long long r=2*1e9+5;
    while (l<r-1){
        long long mid=(l+r)/2;
        long long z=(mid)*(mid+1)/2;
        if (z>n-m-1) r=mid;
        else l=mid;
    }
    if ((l)*(l+1)/2>n-m-1) cout<<l+ans;
    else cout<<r+ans;
}