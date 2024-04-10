#include<bits/stdc++.h>
using namespace std;
int sum[100005];
void work(){
    int n,i,j,x,ans;
    scanf("%d",&n);
    ans=n;
    for(i=1;i<=n;++i){
        scanf("%d",&x);
        sum[i]=sum[i-1]+x;
    }
    for(i=0;i<=n;++i){
        int a=sum[i];
        int b=(n-i-(sum[n]-sum[i]));
        if(a>=b){
            ans=min(ans,a);
        }
    }
    printf("%d\n",ans);
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        work();
    }
    return 0;
}