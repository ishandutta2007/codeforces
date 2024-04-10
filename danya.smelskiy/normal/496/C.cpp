#include <bits/stdc++.h>
using namespace std;

int n,m;
string s[105],ss[105];
bool used[105];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;++i) {
        cin>>s[i];
        s[i]="#"+s[i];
    }
    for (int it=1;it<=m;++it) {
        bool t=false;
        for (int j=2;j<=n;++j) {
            bool tt=false;
            for (int k=1;k<=m;++k)
            if (used[k]==false && s[j][k]<s[j-1][k]) {
                tt=true;
                used[k]=true;
                break;
            } else if (used[k]==false && s[j][k]>s[j-1][k]) break;
            if (tt) {
                t=true;
                break;
            }
        }
        if (t==false) {
            cout<<it-1;
            return 0;
        }
    }
    cout<<m;
}