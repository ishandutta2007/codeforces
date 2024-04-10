#include<bits/stdc++.h>
using namespace std;
int T,n,k;
void solve(){
    scanf("%d %d",&n,&k);
    if(k>(n+1)/2){puts("-1");return;}
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j&&k>0&&i%2==1){k--;printf("R");}
            else printf(".");
        }
        puts("");
    }
}
int main(){
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}