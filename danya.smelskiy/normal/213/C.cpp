#include <bits/stdc++.h>
using namespace std;


int dp[2][305][305];
int a[305][305];
int n;
vector<pair<int,int> > v[1005];
int pos[305][305];
inline void update(int x){
    for (int i=0;i<n;++i)
        for (int j=0;j<n;++j)
            dp[x][i][j]=-1e9;
}
inline void check(int x,int kol,int xx,int yy,int xx2,int yy2){
    if (xx>n || yy>n || xx2>n || yy2>n) return;
    int z1=pos[xx][yy];
    int z2=pos[xx2][yy2];
    if (z1==z2) {
        dp[x][z1][z2]=max(dp[x][z1][z2],kol+a[xx][yy]);
    } else {
        dp[x][z1][z2]=max(dp[x][z1][z2],kol+a[xx][yy]+a[xx2][yy2]);
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i)
        for (int j=1;j<=n;++j)
            cin>>a[i][j];
    for (int i=1;i<=n;++i) {
        int x=i;
        int y=1;
        while (x>0  && y <=n) {
            pos[x][y]=v[i].size();
            v[i].push_back(make_pair(x,y));
            --x; ++y;
        }
    }
    for (int i=n+1;i<n+n;++i) {
        int x=n;
        int y=i-n+1;
        while (x>=0 && y<=n) {
            pos[x][y]=v[i].size();
            v[i].push_back(make_pair(x,y));
            --x; ++y;
        }
    }
    update(0);
    int x=0;
    int y=1;
    dp[x][0][0]=a[1][1];
    for (int i=1;i<n+n-1;++i) {
        swap(x,y);
        update(x);
        for (int j=0;j<v[i].size();++j)
        for (int k=0;k<v[i].size();++k) {
            int xx=v[i][j].first;
            int yy=v[i][j].second;
            int xx2=v[i][k].first;
            int yy2=v[i][k].second;
            check(x,dp[y][j][k],xx+1,yy,xx2+1,yy2);
            check(x,dp[y][j][k],xx,yy+1,xx2,yy2+1);
            check(x,dp[y][j][k],xx+1,yy,xx2,yy2+1);
            check(x,dp[y][j][k],xx,yy+1,xx2+1,yy2);
        }
    }
    cout<<dp[x][0][0];
}