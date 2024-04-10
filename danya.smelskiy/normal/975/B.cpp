#include <bits/stdc++.h>
using namespace std;



long long a[100];
long long b[100];
long long ans;

inline void solve(int x) {
    for (int i=1;i<=14;++i)
        b[i]=a[i];
    long long y=b[x];
    b[x]=0;
    long long z=y/14;
    y%=14;
    for (int i=1;i<=14;++i)
        b[i]+=z;
    int last=x+1;
    if (last>14) last=1;
    while (y) {
        b[last]++;
        --y;
            ++last;
        if (last==15) last=1;
    }
    long long cur=0;
    for (int i=1;i<=14;++i)
        if (b[i]%2ll==0) cur+=b[i];
    ans=max(ans,cur);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    for (int i=1;i<=14;++i)
        cin>>a[i];
    for (int i=1;i<=14;++i) {
        solve(i);
    }
    cout<<ans;
}