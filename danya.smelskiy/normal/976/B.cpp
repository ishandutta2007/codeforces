#include <bits/stdc++.h>
using namespace std;



long long n,m,k;



int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    if (k<n) {
        cout<<k+1ll<<" "<<1;
        return 0;
    }
    k-=n-1;
    long long z=(m-1ll)+(m-1ll);
    long long xx1=k/z;
    k%=z;
    if (!k) {
        long long xx2=n;
        xx2-=xx1+xx1;
        cout<<xx2+1ll<<" "<<2;
        return 0;
    }
    long long yy1=n-xx1-xx1;
    if (k<=m-1ll) cout<<yy1<<" "<<k+1ll;
    else {
        yy1--;
        k-=m-1ll;
        cout<<yy1<<" "<<m-k+1ll;
    }
}