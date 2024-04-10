#include <bits/stdc++.h>
using namespace std;


bool used[305][305];
int n,m,k;
int z;
void dfs(int x,int y,int kol){
    cout<<x<<" "<<y<<" ";
    used[x][y]=true;
    if (kol==1) return;
    if (y<m && used[x][y+1]==false) dfs(x,y+1,kol-1);
    else if (y>1 && used[x][y-1]==false) dfs(x,y-1,kol-1);
    else dfs(x+1,y,kol-1);
}
int main(){
    cin>>n>>m>>k;
    int f=n*m-(k-1)*2;
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j){
            if (used[i][j]==false){
                if (z==0) cout<<f<<" ";  else cout<<"2 ";
                if (z==0) dfs(i,j,f);
                else dfs(i,j,2);
                ++z;
                cout<<'\n';
            }
        }
    }
}