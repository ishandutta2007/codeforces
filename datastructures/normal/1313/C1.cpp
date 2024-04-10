#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;
int n,a[500005];
int mx,id;
inline int work(int ss){
    int last=a[ss],s=a[ss];
    for (int i=ss-1;i>=1;i--)
        if (a[i]<last)s+=a[i],last=a[i];
        else s+=last;
    last=a[ss];
    for (int i=ss+1;i<=n;i++)
        if (a[i]<last)s+=a[i],last=a[i];
        else s+=last;
    return s;
}
signed main(){
 //   freopen("c.in","r",stdin);
 //   freopen("c.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++)scanf("%I64d",&a[i]);
    for (int i=1;i<=n;i++){
        if (work(i)>mx)mx=work(i),id=i;
    }
    int last=a[id];
    for (int i=id-1;i>=1;i--)
        if (a[i]<last)last=a[i];
        else a[i]=last;
    last=a[id];
    for (int i=id+1;i<=n;i++)
        if (a[i]<last)last=a[i];
        else a[i]=last;
    for (int i=1;i<=n;i++)printf("%I64d ",a[i]);
    cout<<endl;
    return 0;
}