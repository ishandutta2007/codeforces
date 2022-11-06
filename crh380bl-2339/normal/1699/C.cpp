#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
int a[100005];
int main(){
    int t,n,m,i,j,x,mn,mx,ans;
    scanf("%d",&t);
    while(t--){
        ans=1;
        scanf("%d",&n);
        for(i=1;i<=n;++i){
            scanf("%d",&x);
            a[x]=i;
        }
        mn=mx=a[0];
        for(i=1;i<n;++i){
            if(a[i]<mn)mn=a[i];
            else if(a[i]>mx)mx=a[i];
            else{
                ans=1LL*ans*(mx-mn+1-i)%mod;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}