#include <bits/stdc++.h>
using namespace std;


long long n,ans,a[150],b[150];
bool used[150];
void dfs(int x,int y,int kol){
    used[x]=true;
    if (a[x]==y) ans=kol;
    if (used[a[x]]==true || a[x]==y) return;
    else dfs(a[x],y,kol+1);
}
int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>a[i];
    }
    for (int i=1;i<=n;++i){
        ans=-1;
        for (int j=1;j<=n;++j)
            used[j]=false;
        dfs(i,i,1);
        if (ans==-1){
            cout<<"-1";
            return 0;
        } else {
            if (ans%2==0) b[i]=ans/2;
            else b[i]=ans;
        }
    }
    ans=b[1];
    for (int i=2;i<=n;++i){
        ans=(ans*b[i])/__gcd(ans,b[i]);
    }
    cout<<ans;
}