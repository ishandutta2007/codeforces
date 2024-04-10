#include<bits/stdc++.h>
using namespace std;
char a[200005];
void work(){
    int n,i,j;
    scanf("%d",&n);
    scanf("%s",a+1);
    int A=0,B=0;
    for(i=1;i<=n;++i){
        if(a[i]=='1')++A;
        else ++B;
    }
    long long ans=0;
    ans=max(ans, 1LL*A*B);
    for(i=1;i<=n;++i){
        for(j=i+1;j<=n&&a[j]==a[i];++j);
        ans=max(ans, 1LL*(j-i)*(j-i));

    }
    printf("%lld\n",ans);
}
int main(){
    int n;
    scanf("%d",&n);
    while(n--)work();
    return 0;
}