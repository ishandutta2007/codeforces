#include<bits/stdc++.h>
using namespace std;
int T,n,k,a[200010];
void solve(){
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    map<int,bool> mp;
    for(int i=1;i<=n;i++){
        if(mp[a[i]-k]||mp[a[i]+k]){puts("YES");return;}
        mp[a[i]]=1;
    }puts("NO");
}
int main(){
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}