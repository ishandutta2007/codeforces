#include <bits/stdc++.h>
using namespace std;
int n,m;
string s[105];
int ans;
int maxd,maxr,maxl=1e9,maxu=1e9;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;++i) {
        cin>>s[i];
        for (int j=1;j<=m;++j) {
            if (s[i][j-1]=='B') {
                maxd=i;
                maxu=min(maxu,i);
                maxl=min(maxl,j);
                maxr=max(maxr,j);
            }
        }
    }
    if (maxd==0) {
        cout<<1;
        return 0;
    }
    while (true) {
        int l1=maxd-maxu+1;
        int l2=maxr-maxl+1;
        if (l1==l2) break;
        if (l1<l2) {
            if (maxd<n) ++maxd;
            else if (maxu>1) --maxu;
            else {
                cout<<"-1";
                return 0;
            }
        } else {
            if (maxr<m) ++maxr;
            else if (maxl>1) --maxl;
            else {
                cout<<"-1";
                return 0;
            }
        }
    }
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=m;++j)
            if (s[i][j-1]=='W' && i>=maxu && i<=maxd && j>=maxl && j<=maxr) ++ans;
    }
    cout<<ans;
}