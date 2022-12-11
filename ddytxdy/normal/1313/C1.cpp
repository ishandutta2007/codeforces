#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=5e5+50;
int n,a[N],st[N],tp,p,c[N];LL s[N],s1[N],s2[N],mx;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        while(tp&&a[st[tp]]>=a[i])tp--;
        st[++tp]=i;s[tp]=s[tp-1]+1ll*(i-st[tp-1])*a[i];
        s1[i]=s[tp];
    }
    tp=0;st[0]=n+1;
    for(int i=n;i;i--){
        while(tp&&a[st[tp]]>=a[i])tp--;
        st[++tp]=i;s[tp]=s[tp-1]+1ll*(st[tp-1]-i)*a[i];
        s2[i]=s[tp];
    }
    for(int i=1;i<=n;i++)if(s1[i]+s2[i]-a[i]>mx)mx=s1[i]+s2[i]-a[i],p=i;
    c[p]=a[p];
    for(int i=p-1;i;i--)c[i]=min(c[i+1],a[i]);
    for(int i=p+1;i<=n;i++)c[i]=min(c[i-1],a[i]);
    for(int i=1;i<=n;i++)printf("%d ",c[i]);
}