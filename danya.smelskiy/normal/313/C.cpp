#include <bits/stdc++.h>
using namespace std;

int n;
long long ans,a[2000005];
inline bool cmp(long long x,long long y) {
    return x>y;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    for (int i=1;i<=n;++i)
        a[i]=a[i-1]+a[i];
    for (int i=1;i<=n;i*=4) {
        ans+=a[i];
    }
    cout<<ans;
}