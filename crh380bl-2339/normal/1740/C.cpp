#include<bits/stdc++.h>
using namespace std;
int a[200005];
void work(){
    int i,n;
    scanf("%d",&n);
    for(i=1;i<=n;++i){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+1+n);
    int ans = 0;
    for(i=1;i<n;++i){
        ans=max(ans, a[i+1]+a[n]-a[i]-a[i]);
        ans=max(ans, a[i+1]+a[i+1]-a[i]-a[1]);
    }
    printf("%d\n",ans);
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--)work();
    return 0;
}