#include<bits/stdc++.h>
using namespace std;
const int N=5e6+50;
int n,f[N],g[N],ans,a[N];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1,num=0,now=0;i<=n;i++){
        if(a[i]==1)num++,now=max(now,num);
        else now++;f[i]=now;
    }
    for(int i=n,num=0,now=0;i;i--){
        if(a[i]==2)num++,now=max(now,num);
        else now++;g[i]=now;
    }
    for(int i=0;i<=n;i++)ans=max(ans,f[i]+g[i+1]);
    printf("%d\n",ans);
    return 0;
}