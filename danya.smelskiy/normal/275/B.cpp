#include <bits/stdc++.h>
using namespace std;


int n,m;
string s[105];
int dp1[105][105];
int dp2[105][105];


inline bool f(int x,int y,int xx,int yy) {
    if (x==xx) {
        if (y>yy) swap(y,yy);
        return (dp1[x][yy]-dp1[x][y-1]==yy-y+1);
    }
    if (x>xx) swap(x,xx);
    return (dp2[xx][y]-dp2[x-1][y]==xx-x+1);
}

inline void check(int x,int y,int xx,int yy) {
    if (x>xx) {
        swap(x,xx);
        swap(y,yy);
    }
    if (f(x,y,x,yy) && f(x,yy,xx,yy)) return;
    if (f(x,y,xx,y) && f(xx,y,xx,yy)) return;
    cout<<"NO";
    exit(0);
}

main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;++i) {
        cin>>s[i];
        s[i]="#"+s[i];
    }
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=m;++j) {
            dp1[i][j]=dp1[i][j-1]+(s[i][j]=='B');
            dp2[i][j]=dp2[i-1][j]+(s[i][j]=='B');
        }
    }
    vector<pair<int,int> > v;

    for (int i=1;i<=n;++i) {
        for (int j=1;j<=m;++j)
        if (s[i][j]=='B') v.push_back({i,j});
    }
    for (int i=0;i<v.size();++i)
        for (int j=i+1;j<v.size();++j)
            check(v[i].first,v[i].second,v[j].first,v[j].second);
    cout<<"YES";
}