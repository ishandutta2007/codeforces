#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N=1e4+50;
int T,n,a[N],ans,s[N];bool f[N];
void solve(){
    scanf("%d",&n);ans=0;
    for(int i=1;i<=n;i++)f[i]=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        s[i]=s[i-1]+a[i];
        for(int j=0;j<i-1;j++)if(s[i]-s[j]<=n)f[s[i]-s[j]]=1;
    }
    for(int i=1;i<=n;i++)ans+=f[a[i]];
    cout<<ans<<endl;
}
int main(){
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}