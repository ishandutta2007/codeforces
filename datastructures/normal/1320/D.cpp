#include <iostream>
#include <cstdio>
#define int long long
#define mod 998244353
using namespace std;
int n,q,x,y,t,len,pos[200005],ch[200005],fac[200005],num[200005],sum[200005];
char s[200005];
inline int getmod(int x){
    return (x%mod+mod)%mod;
}
inline int getsum(int l,int r){
    if (l>r)return 0;
    return getmod(sum[r]-sum[l-1]*fac[r-(l-1)]);
}
inline int getnum(int l,int r){
    return num[r]-num[l-1];
}
inline int lowwer(int x){
    int l=1,r=len,ans=-1;
    while(l<=r){
        int mid=(l+r)/2;
        if (pos[mid]<=x)ans=mid,l=mid+1;
        else r=mid-1;
    }
    return ans;
}
inline int larger(int x){
    int l=1,r=len,ans=-1;
    while(l<=r){
        int mid=(l+r)/2;
        if (pos[mid]>=x)ans=mid,r=mid-1;
        else l=mid+1;
    }
    return ans;
}
inline int getval(int nowl,int nowr){
    int l=larger(nowl),r=lowwer(nowr);
    if (l==-1||r==-1)return -1;
    if (pos[l]>nowr||pos[r]<nowl||l>r)return -1;
    return getmod(getsum(l+1,r)*2+(pos[l]-nowl)%2);
}
signed main(){
    cin>>n;
    scanf("%s",s+1);
    for (int i=1;i<=n;i++){
        num[i]=num[i-1];
        if (s[i]=='0')pos[++len]=i,num[i]++;
    }
    fac[0]=1;
    for (int i=1;i<=n;i++)fac[i]=getmod(fac[i-1]*2);
    for (int i=2;i<=len;i++)ch[i]=(pos[i]-pos[i-1])%2;
    for (int i=2;i<=len;i++)sum[i]=getmod(sum[i-1]*2+ch[i]);
    cin>>q;
    while(q--){
        scanf("%lld%lld%lld",&x,&y,&t);
        if (getval(x,x+t-1)==getval(y,y+t-1)&&getnum(x,x+t-1)==getnum(y,y+t-1))puts("Yes");
        else puts("No");
    }
    return 0;
}