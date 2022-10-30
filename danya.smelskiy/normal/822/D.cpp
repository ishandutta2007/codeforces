#include <bits/stdc++.h>
using namespace std;
const long long md=1e9+7;
long long t,l,r,res;
int f[5000001];
int ans[5000001];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>t>>l>>r;
    for (int i=1;i<=r;++i)
        f[i]=i;
    for (int i=2;i<=r;++i)
        for (int j=i;j<=r;j+=i)
            f[j]=min(f[j],f[i]);
    for (int i=1;i<=r;++i)
        ans[i]=(ans[i/f[i]]+((f[i]*(f[i]-1ll))/2)*(i/f[i]))%md;
    long long last=1;
    for (int i=l;i<=r;++i) {
        res=(res+ans[i]*last)%md;
        last=(last*t)%md;
    }
    cout<<res;
}