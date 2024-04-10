#include <bits/stdc++.h>
using namespace std;






int n,a,b;
char ans[1005][1005];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>a>>b;
    if (a>1) {
        if (b!=1) {
            cout<<"NO";
            return 0;
        }
        a=n-a+1;
        cout<<"YES"<<'\n';
        for (int i=1;i<=n;++i) {
            for (int j=1;j<=n;++j) {
                if (i==j || i>a || j>a) cout<<"0";
                else cout<<"1";
            }
            cout<<'\n';
        }
        return 0;
    }
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=n;++j) {
            if (i!=j) ans[i][j]='1';
            else ans[i][j]='0';
        }
    }
    int c=n;
    if ((n==2 || n==3) && a==1 && a==b) {
        cout<<"NO";
        return 0;
    }
    while (c>b) {
        if (c==2) ans[2][3]=ans[3][2]='0'; else
        ans[1][c]=ans[c][1]='0';
        --c;
    }
    cout<<"YES"<<'\n';
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=n;++j)
            cout<<ans[i][j];
        cout<<'\n';
    }
}