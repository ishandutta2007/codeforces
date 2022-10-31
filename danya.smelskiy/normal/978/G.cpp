#include <bits/stdc++.h>
using namespace std;


int n,m;
int s[1005];
int d[1005];
int c[1005];
int cnt[1005];
int ans[1005];
int used[1005];

int main() {
//    freopen("input.in","r",stdin);
  //  freopen("output.out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=m;++i) {
        cin>>s[i]>>d[i]>>c[i];
        used[d[i]]++;
    }
    for (int i=1;i<=n;++i) {
        if (used[i]>1) {
            cout<<"-1";
            return 0;
        }
        if (used[i]) {
            for (int j=1;j<=m;++j)
            if (d[j]==i) {
                if (cnt[j]!=c[j]) {
                    cout<<"-1";
                    return 0;
                }
                break;
            }
            ans[i]=m+1;
            continue;
        }
        int mn=1e9;
        int pos=0;
        for (int j=1;j<=m;++j) {
            if (s[j]<=i && d[j]>i && cnt[j]<c[j]) {
                if (d[j]<mn) {
                    mn=d[j];
                    pos=j;
                }
            }
        }
        if (pos) {
            ++cnt[pos];
            ans[i]=pos;
        }
    }
    for (int i=1;i<=n;++i)
        cout<<ans[i]<<" ";
}