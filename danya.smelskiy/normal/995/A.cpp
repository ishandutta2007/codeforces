#include <bits/stdc++.h>
using namespace std;



int n,m;

int a[55][55];
bool used[55][55];
int sz;
pair<int,int> q[55*55];
vector<pair<int,pair<int,int> > > qq;
pair<int,int> pred[55][55];

void dfs(int x,int y,int xx,int yy,int z) {
    if (x<1 || x>4 || y<1 || y>n) return;
    if (used[x][y]) return;
    if (a[x][y] && a[x][y]!=z) return;
    used[x][y]=true;
    pred[x][y]=make_pair(xx,yy);
    if (x==1 || x==4) return;
    dfs(x-1,y,x,y,z);
    dfs(x+1,y,x,y,z);
    dfs(x,y-1,x,y,z);
    dfs(x,y+1,x,y,z);
}

inline bool f(int x,int y) {
    for (int i=1;i<=4;++i)
        for (int j=1;j<=n;++j)
            used[i][j]=false;
    dfs(x,y,-1,-1,a[x][y]);
    int xx=-1,yy=-1;
    for (int i=1;i<=n;++i)
    if (a[1][i]==a[x][y]) {
        xx=1;
        yy=i;
        break;
    } else if (a[4][i]==a[x][y]) {
        xx=4;
        yy=i;
        break;
    }
    if (!used[xx][yy]) return false;
    sz=0;
    while (xx!=x || yy!=y) {
        q[++sz]=make_pair(xx,yy);
        int xx1=pred[xx][yy].first;
        int yy1=pred[xx][yy].second;
        xx=xx1;
        yy=yy1;
    }
    for (int i=sz;i>0;--i) {
        qq.push_back(make_pair(a[x][y],q[i]));
    }
    a[x][y]=a[xx][yy]=0;
    return true;
}


inline void mv(int x,int y,int xx,int yy) {
    if (!a[x][y]) return;
    if (x==xx && y==yy) return;
    if (a[xx][yy]) return;
    qq.push_back(make_pair(a[x][y],make_pair(xx,yy)));
    swap(a[x][y],a[xx][yy]);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=4;++i) {
        for (int j=1;j<=n;++j) {
            cin>>a[i][j];
        }
    }
    while (true) {
        bool t=false;
        for (int i=2;i<=3;++i) {
            for (int j=1;j<=n;++j)
                if (a[i][j]) {
                    if (f(i,j)) t=true,--m;
                }
        }
        if(!t) break;
    }
    if (m==n+n) {
        cout<<"-1";
        return 0;
    }
    for (int it=1;it<=2000;++it) {
        if (n==1) break;
        vector<pair<int,int> > vv;
        vv.clear();
        for (int i=n;i>0;--i) {
            vv.push_back(make_pair(3,i));
        }
        for (int i=1;i<=n;++i)
            vv.push_back(make_pair(2,i));
        for (int i=0;i<vv.size();++i) {
            int x=vv[i].first;
            int y=vv[i].second;
            int z=i-1;
            if (z<0) z+=vv.size();
            int xx=vv[z].first;
            int yy=vv[z].second;
            mv(x,y,xx,yy);
        }
        for (int i=2;i<=3;++i) {
            for (int j=1;j<=n;++j)
                if (a[i][j]) {
                    if (f(i,j)) --m;
                }
        }
    }
    if (m || qq.size()>20000) {
        cout<<"-1";
        return 0;
    }
    cout<<qq.size()<<'\n';
    for (int i=0;i<qq.size();++i)
        cout<<qq[i].first<<" "<<qq[i].second.first<<" "<<qq[i].second.second<<'\n';

}