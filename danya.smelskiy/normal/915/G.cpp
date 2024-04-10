#include <bits/stdc++.h>
using namespace std;
const long long md=1e9+7;

int ans[2000005];
int n,m;
int res;


inline long long pw(long long x,long long y) {
    long long res=1;
    while (y) {
        if (y&1) res=(res*x)%md;
        x=(x*x)%md;
        y>>=1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    int last=0;
    int p;
    for (int i=1;i<=m;++i) {
        p=pw(i,n)-pw(i-1,n);
        if (p<0) p+=md;
        ans[i]+=p;
        if (ans[i]>=md) ans[i]-=md;
        for (int j=i+i;j<=m;j+=i) {
            ans[j]-=ans[i];
            if (ans[j]<0) ans[j]+=md;
        }
        last=(last+ans[i]);
        if (last>=md) last-=md;
        res=(res+(last^i));
        if (res>=md) res-=md;
    }
    cout<<res;
}