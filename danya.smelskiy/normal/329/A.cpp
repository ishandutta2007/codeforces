#include <bits/stdc++.h>
using namespace std;

int n;
string ss[105];
bool used1[105],used2[105];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        string s;
        cin>>s;
        ss[i]=s;
        for (int j=1;j<=n;++j)
        if (s[j-1]=='.') {
            used1[i]=true;
            used2[j]=true;
        }
    }
    bool t=false;
    for (int i=1;i<=n;++i)
        if (used1[i]==false) t=true;
    if (t==false) {
        for (int i=1;i<=n;++i) {
            for (int j=1;j<=n;++j)
            if (ss[i][j-1]=='.') {
                cout<<i<<" "<<j<<'\n';
                break;
            }
        }
        return 0;
    }
    t=false;
    for (int i=1;i<=n;++i)
        if (used2[i]==false) t=true;
    if (t) {
        cout<<"-1";
        return 0;
    }
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=n;++j)
        if (ss[j][i-1]=='.') {
            cout<<j<<" "<<i<<'\n';
            break;
        }
    }
}