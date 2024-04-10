#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n,m,a[10005],s[10005],f[200005],ans=2e9;
int q[200005],tail;
inline int mx(register int a,register int b){
    return a>b?a:b;
}
inline int mn(register int a,register int b){
    return a<b?a:b;
}
int main(){
    cin>>n>>m;
    for (int i=1;i<=n;i++)cin>>a[i]>>s[i];
    memset(f,0x7f,sizeof(f));
    f[0]=0;
    tail=0;
    q[++tail]=0;
    for (int i=1;i<=m*2;i++){
        register int len,l,r,xans;
        for (int j=1;j<=n;j++){
            if (a[j]>i)continue;
            len=mx(0,i-(a[j]+s[j]));
            l=0,r=tail,xans=0;
            while(l<=r){
                register int mid=(l+r)>>1;
                if (q[mid]>=mx(0,a[j]-s[j]-len-1))xans=q[mid],r=mid-1;
                else l=mid+1;
            }
            f[i]=mn(f[i],len+f[xans]);
        }
        while(tail>0&&f[q[tail]]>=f[i])tail--;
        q[++tail]=i;
        if (i>=m)ans=min(ans,f[i]);
    }
    cout<<ans<<endl;
    return 0;
}