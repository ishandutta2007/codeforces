#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1e5+50;
int n,a[N],b[N];LL k;
int calc(int x,LL lam){
    int l=0,r=a[x],ans=0;
    while(l<=r){
        int mid=(l+r)>>1;
        if(3ll*mid*mid+3ll*mid+1<=a[x]+lam)ans=mid,l=mid+1;
        else r=mid-1;
    }
    return ans;
}
int main(){
    scanf("%d%lld",&n,&k);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    LL l=-1e9,r=4e18,ans=0;
    while(l<=r){
        LL mid=(l+r)>>1,dat=0;
        for(int i=1;i<=n;i++)dat+=calc(i,mid);
        if(dat>=k)ans=mid,r=mid-1;
        else l=mid+1;
    }
    LL dat=0;
    for(int i=1;i<=n;i++)dat+=(b[i]=calc(i,ans));
    for(int i=1;i<=n;i++)if(dat>k&&3ll*b[i]*b[i]+3ll*b[i]+1==a[i]+ans)b[i]--,dat--;
    for(int i=1;i<=n;i++)printf("%d ",b[i]);
    return 0;
}