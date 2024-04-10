#include <bits/stdc++.h>
using namespace std;

int n,m;
int ans[1000005];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    if (m*3>n) {
        cout<<"-1";
        return 0;
    }
    for (int i=1;i<=m;++i)
        ans[i]=i;
    for (int i=1;i<=m;++i)
        ans[m+i]=i;
    int last=2;
    for (int i=1;i<=m;++i) {
        int x=m+m+i;
        ans[x]=last;
        ++last;
        if (last==m+1) last=1;
    }
    for (int i=3*m+1;i<=n;++i)
        ans[i]=1;
    for (int i=1;i<=n;++i)
        cout<<ans[i]<<" ";
}