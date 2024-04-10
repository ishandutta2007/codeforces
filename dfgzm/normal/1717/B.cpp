#include<bits/stdc++.h>
using namespace std;
const int maxn=510;
int i,j,k,n,m,T,is[maxn][maxn];
void dfs(int x,int y){
    // cerr<<"dfs "<<x<<' '<<y<<endl;
    if(x<1 || x>n || y<1 || y>m)return;
    if(is[x][y])return;
    is[x][y]=1;
    dfs(x-1,y-1);
    dfs(x,y-m);
    dfs(x+1,y+1);
    dfs(x,y+m);
}
int main(){
    cin>>T;
    while(T--){
        int r,c;
        cin>>n>>m>>r>>c;
        // is[r][c]=1;
        // dfs(r,c);
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++)
                if((j-i+n)%m==(c-r+n)%m)putchar('X');
                else putchar('.');
            puts("");
        }
    }
}