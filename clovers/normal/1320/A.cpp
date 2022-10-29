#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
int n; ll a[N],t[N<<2],ans=0;

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        t[a[i]+n-i]+=a[i];
    }
    for(int i=1;i<=800000;i++){
        ans=max(ans,t[i]);
    }
    cout<<ans<<endl;
    return 0;
}