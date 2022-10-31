#include <bits/stdc++.h>
using namespace std;
int n,k;
int kol[2000005];
int x;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    int mn=1e9;
    for (int i=1;i<=n;++i) {
        cin>>x;
        ++kol[x];
        mn=min(mn,x);
    }
    for (int i=1;i<=2e6;++i)
        kol[i]=kol[i-1]+kol[i];
    if (mn<=k+1) {
        cout<<mn;
        return 0;
    }
    int ans=0;
    ans=k;
    for (int i=k+1;i<=mn;++i) {
        int z=0;
        for (int j=i;j<=1e6;j+=i)
            z+=kol[j+k]-kol[j-1];
        if (z==n) ans=i;
    }
    cout<<ans;
}