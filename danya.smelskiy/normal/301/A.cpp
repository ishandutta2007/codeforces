#include <bits/stdc++.h>
using namespace std;

bool used[205];
int n;
int a[205];
int c1,c2,c3;


void dfs(int x,int y) {
    used[x]=true;
    for (int i=0;i<=min(n,x);++i) {
        int kol=n-i;
        kol-=y;
        kol=max(kol,0);
        if (kol<=n+n-1-x-y && used[x-i+kol]==false) dfs(x-i+kol,y);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n+n-1;++i) {
        cin>>a[i];
        if (a[i]<0) ++c1;
        else if (a[i]==0) ++c2;
        else ++c3;
        a[i]=abs(a[i]);
    }
    dfs(c1,c2);
    if (used[0]) {
        int ans=0;
        for (int i=1;i<=n+n-1;++i)
        ans+=a[i];
        cout<<ans;
    } else {
        int ans=0;
        sort(a+1,a+n+n-2);
        for (int i=2;i<n+n;++i)
        ans+=a[i];
        ans-=a[1];
        cout<<ans;
    }
}