#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    int cp,cq;
    cin >> cp >> cq;
    vector<string> s(n);
    for(int i=0;i<n;i++) cin >> s[i];
    auto in=[&](int r,int c)->bool{return (0<=r&&r<n&&0<=c&&c<m);};
    const ll inf=(1ll<<60);
    vector d(n,vector(m,ll(inf)));
    priority_queue<array<ll,3>,vector<array<ll,3>>,greater<>> q;
    auto add=[&](int r,int c,ll nd)
    {
        if(s[r][c]!='#'&&nd<d[r][c])
        {
            d[r][c]=nd;
            q.push({nd,r,c});
        }
    };
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(s[i][j]=='.') add(i,j,0);
    auto t=[&](int r,int c)->char
    {
        if(in(r,c)) return s[r][c];
        else return '$';
    };
    while(!q.empty())
    {
        auto [da,r,c]=q.top();
        q.pop();
        if(d[r][c]<da) continue;
        if(in(r,c+2)&&t(r,c+1)=='L') add(r,c+2,da+cq);
        if(in(r,c-2)&&t(r,c-1)=='R') add(r,c-2,da+cq);
        if(in(r+2,c)&&t(r+1,c)=='U') add(r+2,c,da+cq);
        if(in(r-2,c)&&t(r-1,c)=='D') add(r-2,c,da+cq);
        if(in(r+1,c+1)&&(t(r,c+1)=='U'||t(r+1,c)=='L')) add(r+1,c+1,da+cp);
        if(in(r-1,c+1)&&(t(r,c+1)=='D'||t(r-1,c)=='L')) add(r-1,c+1,da+cp);
        if(in(r-1,c-1)&&(t(r,c-1)=='D'||t(r-1,c)=='R')) add(r-1,c-1,da+cp);
        if(in(r+1,c-1)&&(t(r,c-1)=='U'||t(r+1,c)=='R')) add(r+1,c-1,da+cp);
    }
    ll res=inf;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(in(i,j+1)) res=min(res,d[i][j]+d[i][j+1]);
            if(in(i+1,j)) res=min(res,d[i][j]+d[i+1][j]);
        }
    }
    if(res==inf) res=-1;
    cout << res << "\n";
    return 0;
}