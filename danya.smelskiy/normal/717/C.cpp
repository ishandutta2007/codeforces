#include<bits/stdc++.h>
#define bs ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ll long long
#define ull unsigned long long
#define sqr(a) ((a)*(a))
using namespace std;
ll ans,a[100001],n;
int main(){
//    freopen("friends.in","r",stdin);
  //  freopen("friends.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;++i) cin>>a[i];
    sort(a,a+n+1);
    for (int i=1;i<=n;++i)
        ans=(ans+((a[i]%10007)*(a[n-i+1]%10007)))%10007;
        cout<<ans%10007;
}