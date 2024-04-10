#include <bits/stdc++.h>
using namespace std;
const long long md=998244353;

int n;
long long p[1000005];
long long a[1000005];
long long res1,res2;
long long res;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    p[0]=1;
    for (int i=1;i<=n;++i) {
        p[i]=p[i-1]+p[i-1];
        if (p[i]>=md) p[i]-=md;
    }
    long long cur;
    for (int i=1;i<=n;++i) {
        res1+=a[i]*p[n-i];
        res1%=md;
        if (i<n) {
            cur=a[i]*p[n-i-1];
            cur%=md;
            res2+=cur*1ll*(n-i);
            res2%=md;
        }
    }
    res1+=res2;
    if (res1>=md) res1-=md;
    cout<<res1;
}