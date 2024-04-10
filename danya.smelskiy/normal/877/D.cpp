#include <bits/stdc++.h>
using namespace std;




int n,m,k;
string s[1005];
int up[1005][1005],dwn[1005][1005],l[1005][1005],r[1005][1005];
set<int> q1[1005],q2[1005];
bool used[1005][1005];
vector<pair<int,int> > q;
int d[1005][1005];
int x2,y2,x3,y3;
vector<pair<int,int> > zz;
inline void add(int x,int y){
    if (used[x][y]) return;
    used[x][y]=true;
    zz.push_back(make_pair(x,y));
    q.push_back(make_pair(x,y));
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    for (int i=1;i<=n;++i) {
        cin>>s[i];
        s[i]="."+s[i];
    }
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=m;++j) {
            if (s[i][j]=='.') {
                q1[i].insert(j);
                q2[j].insert(i);
                up[i][j]=up[i-1][j];
                l[i][j]=l[i][j-1];
            } else {
                up[i][j]=i;
                l[i][j]=j;
            }
        }
    }
    for (int i=n;i>0;--i) {
        r[i][m+1]=m+1;
        for (int j=m;j>0;--j) {
            if (i==n) dwn[i+1][j]=n+1;
            if (s[i][j]=='.') {
                dwn[i][j]=dwn[i+1][j];
                r[i][j]=r[i][j+1];
            } else {
                dwn[i][j]=i;
                r[i][j]=j;
            }
        }
    }
    for (int i=1;i<=n;++i)
        for (int j=1;j<=m;++j)
            d[i][j]=1e9;
    cin>>x2>>y2>>x3>>y3;
    d[x2][y2]=0;
    q.push_back(make_pair(x2,y2));
    for (int i=0;i<q.size();++i) {
        int xx=q[i].first;
        int yy=q[i].second;
        q1[xx].erase(yy);
        q2[yy].erase(xx);
        used[xx][yy]=true;
        zz.clear();
        set<int> ::iterator s1=q2[yy].lower_bound(max(up[xx][yy],xx-k));
        while (s1!=q2[yy].end()) {
            int yy2=*s1;
            if (yy2>dwn[xx][yy] || yy2>xx+k) break;
            add(yy2,yy);
            d[yy2][yy]=min(d[yy2][yy],d[xx][yy]+1);
            ++s1;
        }
        s1=q1[xx].lower_bound(max(l[xx][yy],yy-k));
        while (s1!=q1[xx].end()) {
            int yy2=*s1;
            if (yy2>r[xx][yy] || yy2>yy+k) break;
            add(xx,yy2);
            d[xx][yy2]=min(d[xx][yy2],d[xx][yy]+1);
            ++s1;
        }
        for (int j=0;j<zz.size();++j) {
            int xx2=zz[j].first;
            int yy2=zz[j].second;
            q1[xx2].erase(yy2);
            q2[yy2].erase(xx2);
        }
    }
    cout<<(d[x3][y3]==1e9 ? -1 : d[x3][y3]);
}