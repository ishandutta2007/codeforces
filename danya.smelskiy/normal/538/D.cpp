#include <bits/stdc++.h>
using namespace std;


int n;
string s[105];
bool ans[105][105];
bool ans2[105][105];
int m;


inline void solve(int x,int y) {
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=n;++j) if (s[i][j]=='.') {
            int xx=i-x;
            int yy=j-y;
            ans[n+xx][n+yy]=true;
        }
    }
}

inline void solve2(int x,int y) {
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=n;++j) {
            int xx=i-x;
            int yy=j-y;
            if (ans[n+xx][n+yy]) ans2[i][j]=true;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>s[i];
        s[i]="#"+s[i];
    }
    for (int i=1;i<=n;++i)
        for (int j=1;j<=n;++j)
            if (s[i][j]=='o') solve(i,j);
    m=n+n-1;
    for (int i=1;i<=m;++i)
        for (int j=1;j<=m;++j)
            ans[i][j]^=1;

    for (int i=1;i<=n;++i)
        for (int j=1;j<=n;++j)
            if (s[i][j]=='o') solve2(i,j);
    for (int i=1;i<=n;++i)
    for (int j=1;j<=n;++j) {
        if (s[i][j]=='.' && ans2[i][j]) {
            cout<<"NO";
            return 0;
        }
        if (s[i][j]=='x' && !ans2[i][j]) {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES"<<'\n';
    for (int i=1;i<=m;++i) {
        for (int j=1;j<=m;++j) {
            if (i==n && j==n) cout<<"o"; else
            cout<<(ans[i][j] ? 'x' : '.');
        }
        cout<<'\n';
    }
}