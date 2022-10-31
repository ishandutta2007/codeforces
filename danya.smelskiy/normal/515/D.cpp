#include <bits/stdc++.h>
using namespace std;

int n,m;
string s[2005];
vector<pair<short,short> > v[2005][2005];
pair<short ,short> q[2005*2005];
int xd[4];
int yd[4];
bool used[2005][2005];
char ans[2005][2005];
int sz;
short cnt[2005][2005];


int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    xd[0]=-1;
    yd[0]=0;
    xd[1]=0;
    yd[1]=1;
    xd[2]=1;
    yd[2]=0;
    xd[3]=0;
    yd[3]=-1;
    cin>>n>>m;
    for (int i=1;i<=n;++i) {
        cin>>s[i];
        s[i]="#"+s[i];
    }
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=m;++j) if (s[i][j]!='*') {
            for (int k=0;k<4;++k) {
                int xx=i+xd[k];
                int yy=j+yd[k];
                if (xx==0 || xx>n || yy==0 || yy>m) continue;
                if (s[xx][yy]=='*') continue;
                v[i][j].push_back(make_pair(xx,yy));
                ++cnt[i][j];
            }
            if (cnt[i][j]==1) q[++sz]=make_pair(i,j);
        }
    }
    for (int i=1;i<=sz;++i) {
        int x=q[i].first;
        int y=q[i].second;
        if (used[x][y]) continue;
        used[x][y]=true;
        for (int i=0;i<v[x][y].size();++i) {
            int xx=v[x][y][i].first;
            int yy=v[x][y][i].second;
            if (used[xx][yy]) continue;
            for (int j=0;j<v[xx][yy].size();++j) {
                int xx2=v[xx][yy][j].first;
                int yy2=v[xx][yy][j].second;
                if (used[xx2][yy2]==false) {
                    --cnt[xx2][yy2];
                    if (cnt[xx2][yy2]==1) {
                        q[++sz]=make_pair(xx2,yy2);
                    }
                }
            }
            used[xx][yy]=true;
            if (xx==x) {
                ans[x][y]='<';
                ans[xx][yy]='>';
                if (yy<y) swap(ans[x][y],ans[xx][yy]);
            } else {
                ans[x][y]='^';
                ans[xx][yy]='v';
                if (xx<x) swap(ans[x][y],ans[xx][yy]);
            }
        }
    }
    for (int i=1;i<=n;++i)
        for (int j=1;j<=m;++j)
    if (s[i][j]=='.' && !ans[i][j]) {
        cout<<"Not unique";
        return 0;
    }
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=m;++j)
            cout<<( ans[i][j] ? ans[i][j] : '*' );
        cout<<'\n';
    }
}