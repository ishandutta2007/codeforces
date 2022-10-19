#include<bits/stdc++.h>
using namespace std;
int T,n,a[10010],b[10010];
void solve(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]),b[i]=a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        if(a[i]!=b[i]){puts("YES");return;}
    } puts("NO");
}
int main(){
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}