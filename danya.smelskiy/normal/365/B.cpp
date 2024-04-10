#include <bits/stdc++.h>
using namespace std;

int n;
int ans;
int l[100005];
int a[100005];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    l[1]=1;
    l[2]=1;
    for (int i=3;i<=n;++i)
        if (a[i]==a[i-1]+a[i-2]) l[i]=l[i-1]+1;
        else l[i]=1;
    for (int i=1;i<=n;++i)
        ans=max(ans,l[i]);
    if (n==1) cout<<1;
    else if (n==2) cout<<2;
    else cout<<ans+1;
}