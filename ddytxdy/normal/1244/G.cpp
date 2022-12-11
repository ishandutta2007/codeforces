#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1e6+50;
int n,a[N];LL k,ans;
int main(){
    cin>>n>>k;ans=1ll*n*(n+1)/2;
    if(k<ans)puts("-1"),exit(0);
    for(int i=1;i<=n;i++)a[i]=i;
    for(int i=1;i<=n/2;i++){
        int re=n-(i-1)*2;
        if(re-1>=k-ans){swap(a[i],a[i+k-ans]);ans=k;break;}
        swap(a[i],a[n-i+1]);ans+=re-1;
    }
    cout<<ans<<endl;
    for(int i=1;i<=n;i++)printf("%d ",i);puts("");
    for(int i=1;i<=n;i++)printf("%d ",a[i]);
    return 0;
}