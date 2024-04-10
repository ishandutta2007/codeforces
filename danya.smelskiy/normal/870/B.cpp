#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[100005];
int pref[100005];
int suff[100005];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    if (m>=3) {
        int res=-2e9;
        for (int i=1;i<=n;++i)
            res=max(res,a[i]);
        cout<<res;
        return 0;
    }
    if (m==1) {
        int res=2e9;
        for (int i=1;i<=n;++i)
            res=min(res,a[i]);
        cout<<res;
        return 0;
    }
    pref[0]=2e9;
    for (int i=1;i<=n;++i) {
        pref[i]=min(pref[i-1],a[i]);
    }
    suff[n+1]=2e9;
    for (int i=n;i>0;--i) {
        suff[i]=min(suff[i+1],a[i]);
    }
    int res=-2e9;
    for (int i=1;i<n;++i)
        res=max(res,max(pref[i],suff[i+1]));
    cout<<res;
}