#include<bits/stdc++.h>
using namespace std;
long long sum[100005],a[100005];
void work(){
    int n,m,j;
    scanf("%d%d",&n,&m);
    int i;
    for(i=n-m+1;i<=n;++i)scanf("%lld",&sum[i]);
    if(m==1){
        puts("Yes");
        return;
    }
    for(i=n-m+2;i<=n;++i)a[i]=sum[i]-sum[i-1];
    for(i=1;i<=n-m+1;++i)a[i]=a[n-m+2];
    for(i=1;i<n;++i){
        if(a[i]>a[i+1]){
            puts("No");
            return;
        }
    }
    if(1LL*(n-m+1)*a[1]<sum[n-m+1]){
        puts("No");
    }
    else puts("Yes");
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        work();
    }
    return 0;
}