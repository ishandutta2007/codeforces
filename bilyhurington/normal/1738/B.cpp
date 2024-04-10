#include<bits/stdc++.h>
using namespace std;
int T,n,k;
long long s[100010];
void solve(){
    scanf("%d %d",&n,&k);
    for(int i=n-k+1;i<=n;i++) scanf("%lld",&s[i]);
    if(k==1){puts("Yes");return;}
    for(int i=n;i>n-k+1;i--) s[i]-=s[i-1];
    for(int i=n-k+2;i<n;i++){
        if(s[i]>s[i+1]){
            puts("No");
            return;
        }
    }long long v=s[n-k+2];
    if(s[n-k+1]>(n-k+1)*v){puts("No");return;}
    else puts("Yes");
}
int main(){
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}