#include<bits/stdc++.h>
using namespace std;
const int N=110;
int n,a[N],b[N],c[N],now,ans;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%1d",&c[i]),now+=c[i];
    for(int i=1;i<=n;i++)scanf("%d%d",&a[i],&b[i]);
    ans=now;
    for(int i=1;i<=100000;i++){
        for(int j=1;j<=n;j++)if(i>=b[j]&&(i-b[j])%a[j]==0){
            if(c[j])c[j]=0,now--;
            else c[j]=1,now++;
        }
        ans=max(ans,now);
    }
    printf("%d\n",ans);
    return 0;
}