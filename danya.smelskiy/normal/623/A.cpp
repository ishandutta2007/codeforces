#include <bits/stdc++.h>
using namespace std;
int n,m;
int x,y;
vector<int> v[501];
int a[501][501];
int color[501];
int main(){
    cin>>n>>m;
    ///
    for (int i=1;i<=m;++i){
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
        a[x][y]=1;
        a[y][x]=1;
    }
    for (int i=1;i<=n;++i)
    if (!color[i])  {
        bool t=false;
        for (int j=1;j<=n;++j){
            if (i!=j)
        for (int z=j+1;z<=n;++z){
            if (a[i][j] && a[i][z] && !a[j][z]) {
                t=true;
                break;
            }
        }
        if (t) break;
        }
        if (t) color[i]=2;
    }
    int last=0;
    for (int i=1;i<=n;++i)
    if (!color[i]) {
        ++last;
        if (last==2) last=3;
        color[i]=last;
        for (int j=0;j<v[i].size();++j){
            int to=v[i][j];
            if (!color[to]) color[to]=last;
        }
    }
    for (int i=1;i<=n;++i){
        for (int j=1;j<=n;++j) if (i!=j) {
            if ((a[i][j]==1 && abs(color[i]-color[j])>1) || (a[i][j]==0 && abs(color[i]-color[j])<=1)) {
                cout<<"No";
                return 0;
            }
        }
    }
    cout<<"Yes"<<'\n';
    for (int i=1;i<=n;++i){
        if (color[i]==3) cout<<"c";
        else if (color[i]==2) cout<<"b";
        else cout<<"a";
    }

}