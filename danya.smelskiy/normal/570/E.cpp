#include <bits/stdc++.h>
using namespace std;
const int md=1e9+7;
int n,m,l,r;
vector<pair<int,int> > v[1005];
string s[505];
int dp1[505][505];
int dp2[505][505];
inline void mk(int x,int y,int xx,int yy){
    if (y>1) {
        if (xx<n) {
            if (s[x][y-2]==s[xx+1][yy-1]) dp2[x][xx+1]=(dp2[x][xx+1]+dp1[x][xx])%md;
        }
        if (yy<m) {
            if (s[x][y-2]==s[xx][yy]) dp2[x][xx]=(dp2[x][xx]+dp1[x][xx])%md;
        }
    }
    if (x>1) {
        if (xx<n) {
            if (s[x-1][y-1]==s[xx+1][yy-1]) dp2[x-1][xx+1]=(dp2[x-1][xx+1]+dp1[x][xx])%md;
        }
        if (yy<m) {
            if (s[x-1][y-1]==s[xx][yy]) dp2[x-1][xx]=(dp2[x-1][xx]+dp1[x][xx])%md;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;++i)
        cin>>s[i];
    for (int i=1;i<=n+m-1;++i) {
        int x=i;
        int y=1;
        while (x>0 && y<=m) {
            if (x<=n && y<=m) {
                v[i].push_back(make_pair(x,y));
                if (x-1+y-1==n-x+m-y) {
                    l=i;
                    r=i;
                } else if ((n+m-1)%2==0 && x-1+y-1==(n+m-1)/2-1) l=i;
                else if ((n+m-1)%2==0 && x-1+y-1==(n+m-1)/2) r=i;
            }
            --x;
            ++y;
        }
    }
    if (l==r) {
        for (int i=0;i<v[l].size();++i) {
            int x=v[l][i].first;
            int y=v[l][i].second;
            dp1[x][x]=1;
        }
    } else {
        for (int i=0;i<v[l].size();++i) {
            int x=v[l][i].first;
            int y=v[l][i].second;
            if (y+1<=m && s[x][y]==s[x][y-1]) dp1[x][x]=1;
            if (x+1<=n && s[x][y-1]==s[x+1][y-1]) dp1[x][x+1]=1;
        }
    }
    while (l>1) {
        for (int i=0;i<v[l].size();++i) {
            int x=v[l][i].first;
            int y=v[l][i].second;
            for (int j=0;j<v[r].size();++j) {
                int xx=v[r][j].first;
                int yy=v[r][j].second;
                if (xx>=x && yy>=y)
                if (dp1[x][xx]) mk(x,y,xx,yy);
            }
        }
        for (int i=1;i<=n;++i)
            for (int j=i;j<=n;++j)
            dp1[i][j]=dp2[i][j],dp2[i][j]=0;
        --l;
        ++r;
    }
    cout<<dp1[1][n];
}