#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1e6+50,D=5e5;
int n,a[N];LL ans,f[N];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        f[a[i]-i+D]+=a[i];ans=max(ans,f[a[i]-i+D]);
    }
    cout<<ans;
    return 0;
}