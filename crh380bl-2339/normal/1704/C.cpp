#include<bits/stdc++.h>
using namespace std;
int a[100005];
int d[100005];
void work(){
    int n,m,i;
    long long ans=0,t=1;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;++i){
        scanf("%d",&a[i]);
        --a[i];
    }
    sort(a+1,a+1+m);
    for(i=1;i<=m;++i){
        d[i]=(1LL*a[i%m+1]-1LL*a[i]+n-1)%n;
    }
    sort(d+1,d+1+m);
    if(d[m]==0){
        printf("%d\n",n);
        return;
    }
    if(d[m]==1){
        printf("%d\n",n-1);
        return;
    }
    for(i=m;i>=1;--i){
        //printf("%d ",d[i]);
        long long tmp=1LL*d[i]-t;
        if(tmp==0){
            ++ans;
            break;
        }
        else ans+=max(0LL,tmp);
        t+=4LL;
    }
    printf("%lld\n",1LL*n-ans);
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--)work();
    return 0;
}