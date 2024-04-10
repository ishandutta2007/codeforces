#include <bits/stdc++.h>
using namespace std;




int n;
string s[105];


inline void check(int x,int y) {
    if (y==1 || y==n || x==n || x==n-1) {
        cout<<"NO";
        exit(0);
    }
    s[x][y]='.';
    for (int i=y-1;i<=y+1;++i)
    if (s[x+1][i]!='#') {
        cout<<"NO";
        exit(0);
    } else s[x+1][i]='.';
    if (s[x+2][y]!='#') {
        cout<<"NO";
        exit(0);
    }
    s[x+2][y]='.';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>s[i];
        s[i]="."+s[i];
    }
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=n;++j)
            if (s[i][j]=='#') check(i,j);
    }
    cout<<"YES";
}