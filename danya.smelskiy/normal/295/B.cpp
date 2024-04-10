#include <bits/stdc++.h>
using namespace std;

long long n,ans[501],a[501][501],c[501];
int main(){
    cin>>n;
    for (int i=1;i<=n;++i)
        for (int j=1;j<=n;++j)
        cin>>a[i][j];
    for (int i=1;i<=n;++i)
        cin>>c[n-i+1];
    for (int i=1;i<=n;++i){
        for (int j=1;j<=n;++j)
            for (int z=1;z<=n;++z)
                a[c[j]][c[z]]=min(a[c[j]][c[z]],a[c[j]][c[i]]+a[c[i]][c[z]]);
        long long now=0;
        for (int j=1;j<=i;++j)
            for (int z=1;z<=i;++z)
                if (j!=z)
                now+=a[c[j]][c[z]];
        ans[i]=now;
    }
    for (int i=n;i>0;--i)
        cout<<ans[i]<<" ";
}