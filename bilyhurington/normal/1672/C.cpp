#include<bits/stdc++.h>
using namespace std;
int T,n,a[200010];
void solve(){
    scanf("%d",&n);int cnt=0,ans=0;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<n;i++) cnt+=a[i]==a[i+1];
    for(int i=1;i<n;i++){
        if(cnt<=1) break;
        if(a[i]==a[i+1]){
            if(a[i+1]==a[i+2]) cnt--;
            if(i<=n-3&&a[i+2]==a[i+3]) cnt--;
            a[i+1]=a[i+2]=0;
            ans++;
            // printf("%d %d\n",i,cnt);
        }
    }
    printf("%d\n",ans);
}
int main(){
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}