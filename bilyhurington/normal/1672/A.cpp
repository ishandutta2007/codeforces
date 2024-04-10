#include<bits/stdc++.h>
using namespace std;
int T,n,a[110];
void solve(){
    scanf("%d",&n);int s=0;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]),s+=a[i]-1;
    if(s&1) puts("errorgorn");
    else puts("maomao90");
}
int main(){
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}