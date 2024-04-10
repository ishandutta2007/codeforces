#include <bits/stdc++.h>
using namespace std;

const long long C=1e18;

long long n,k,m,d;
long long ans;

inline void solve(long long x,long long y) {
    if(!x) return;
    long long z=x;
    z=min(z,m);
    if (z==0) return;
    ans=max(ans,z*y);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k>>m>>d;
    for (int i=0;i<=d;++i) {
        long long x=i;
        x*=k;
        if (x){
            x=(n/x);
            solve(x,i);
        }
        x=i;
        x*=k;
        x++;
        x=n/x;
        if (i<d) solve(x,i+1);
        x=i;
        x*=k;
        if (x>n) break;
    }
    cout<<ans;
}