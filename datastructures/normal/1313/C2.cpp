#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;
int n,a[500005];
int l[500005],r[500005];
int q[500005],tail;
int mx,id;
signed main(){
 //   freopen("c.in","r",stdin);
 //   freopen("c.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++)scanf("%I64d",&a[i]);
    q[++tail]=0;
    for (int i=1;i<=n;i++){
        while(tail&&a[q[tail]]>a[i])tail--;
        l[i]=l[q[tail]]+(i-q[tail])*a[i];
        q[++tail]=i;
    }
    q[tail=1]=n+1;
    for (int i=n;i>=1;i--){
        while(tail&&a[q[tail]]>a[i])tail--;
        r[i]=r[q[tail]]+(q[tail]-i)*a[i];
        q[++tail]=i;
    }
    for (int i=1;i<=n;i++){
        if (l[i]+r[i]-a[i]>mx)mx=l[i]+r[i]-a[i],id=i;
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