#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
using namespace std;
int n,k,a[1000005];
inline bool check(int x){
    int i,rest=k,num=0;
    for (int i=n;i>=1;i--){
        if (a[i]>=x){
            num++;
            continue;
        }
        if (x-a[i]<=rest)num++,rest-=x-a[i];
    }
    return num>=(n+1)/2;
}
signed main(){
    cin>>n>>k;
    for (int i=1;i<=n;i++)scanf("%lld",&a[i]);
    sort(a+1,a+1+n);
    int l=0,r=2e9,ans=-1;
    while(l<=r){
        int mid=(l+r)/2;
        if (check(mid))ans=mid,l=mid+1;
        else r=mid-1;
    }
    cout<<ans<<endl;
    return 0;
}