#include <bits/stdc++.h>
using namespace std;

int n,m,k;
long long ans;
string s[2005];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    if (k==1) {
        for (int i=1;i<=n;++i) {
            cin >>s[i];
            s[i]="#"+s[i];
            for (int j=1;j<=m;++j)
                if (s[i][j]=='.') ++ans;
        }
        cout<<ans;
        return 0;
    }
    for (int i=1;i<=n;++i) {
        long long last=0;
        cin>>s[i];
        s[i]="#"+s[i];
        for (int j=1;j<=m;++j) {
            if (s[i][j]=='.') ++last;
            else last=0;
            if (last>=k) ans++;
        }
    }
    for (int j=1;j<=m;++j) {
        long long last=0;
        for (int i=1;i<=n;++i) {
            if (s[i][j]=='.') ++last;
            else last=0;
            if (last>=k) ans++;
        }
    }
    cout<<ans;
}