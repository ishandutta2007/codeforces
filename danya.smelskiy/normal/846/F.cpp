#include <bits/stdc++.h>
using namespace std;


long long tree[7000005];
long long q[7000005];
long long  n,sz;
long long ans;
long long x;
long long last[2000005];

main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    long long kol=0;
    sz=1;
    while (sz<1e6) sz+=sz;
    long long ans4=0;
    for (long long i=1;i<=n;++i) {
        cin>>x;
        if (last[x]==0) ans4+=i;
        else ans4+=i-last[x];
        ans+=ans4;
        last[x]=i;
    }
    ans-=n;
    long double ans2=((long double)1/(long double)n);
    long double ans3=(long double)2/((long double)(n*n));
    cout<<fixed<<setprecision(6)<<ans2+(long double)ans*ans3;
}