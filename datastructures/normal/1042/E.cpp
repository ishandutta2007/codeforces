#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
#define mod 998244353
using namespace std;
int r,c,rr,cc,s[1005][1005];
struct node{
    int x,y,val;
}a[1000005];
int n,f[1000005],cnt,sum,sx[2],sy[2],ans;
inline int pw(register int a,register int p){
    if (p==0)return 1;
    register int t=pw(a,p/2);
    t=t*t%mod;
    if (p%2==1)t=t*a%mod;
    return t;
}
inline int inv(int a){
    return pw(a,mod-2);
}
bool cmp(node a,node b){
    return a.val<b.val;
}
inline void insx(int x){
    sx[0]+=x*x,sx[0]%=mod;
    sx[1]+=x,sx[1]%=mod;
    return;
}
inline void insy(int y){
    sy[0]+=y*y,sy[0]%=mod;
    sy[1]+=y,sy[1]%=mod;
    return;
}
inline int calcx(int x){
    int ans=x*x%mod*cnt%mod+sx[0]-2*x%mod*sx[1]%mod;
    return (ans%mod+mod)%mod;
}
inline int calcy(int y){
    int ans=y*y%mod*cnt%mod+sy[0]-2*y%mod*sy[1]%mod;
    return (ans%mod+mod)%mod;
}
signed main(){
    cin>>r>>c;
    for (int i=1;i<=r;i++)
        for (int j=1;j<=c;j++){
            scanf("%lld",&s[i][j]);
            ++n;
            a[n].x=i,a[n].y=j,a[n].val=s[i][j];
        }
    cin>>rr>>cc;
    sort(a+1,a+1+n,cmp);
    int i=1,j=1;
    for (;i<=n;i++){
        while(j<i&&a[j].val<a[i].val){
            insx(a[j].x);
            insy(a[j].y);
            cnt++;
            sum+=f[j];
            sum%=mod;
            j++;
        }
        f[i]=(f[i]+(calcx(a[i].x)+calcy(a[i].y))*inv(cnt))%mod;
        f[i]=(f[i]+sum*inv(cnt))%mod;
        if (a[i].x==rr&&a[i].y==cc)break;
    }
    cout<<f[i]<<endl;
    return 0;
}
//(a-b)^2=a^2+b^2-2*a*b