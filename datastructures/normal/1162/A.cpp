#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
int n,m,h,a[105],l,r,x,ans;
signed main(){
    cin>>n>>h>>m;
    for (int i=1;i<=n;i++)a[i]=h;
    for (int i=1;i<=m;i++){
        cin>>l>>r>>x;
        for (int j=l;j<=r;j++)a[j]=min(a[j],x);
    }
    for (int i=1;i<=n;i++)ans+=a[i]*a[i];
    cout<<ans<<endl;
    return 0;
}