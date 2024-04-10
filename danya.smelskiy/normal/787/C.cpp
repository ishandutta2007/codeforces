#include <bits/stdc++.h>
using namespace std;


int n,kol[2],a[2][7005];
int ans[7005][2];
int kk[7005][2];

void bfs(int x,int y){
    int next=y^1;
    for (int i=1;i<=kol[next];++i) {
        int pos=x-a[next][i];
        if (pos<=0) pos+=n;
        if (pos==1) continue;
        if (ans[x][y]==-1 && ans[pos][next]!=1) {
            ans[pos][next]=1;
            bfs(pos,next);
        }
        if (ans[x][y]==1 && ans[pos][next]==0) {
            ++kk[pos][next];
            if (kk[pos][next]!=kol[next]) continue;
            ans[pos][next]=-1;
            bfs(pos,next);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    cin>>kol[0];
    for(int i=1;i<=kol[0];++i)
        cin>>a[0][i];
    cin>>kol[1];
    for (int i=1;i<=kol[1];++i)
        cin>>a[1][i];
    ans[1][0]=-1;
    ans[1][1]=-1;
    bfs(1,0);
    bfs(1,1);
    for (int i=0;i<=1;++i){
        for (int j=2;j<=n;++j)
            if (ans[j][i]==0) cout<<"Loop ";
            else if (ans[j][i]==1) cout<<"Win ";
            else cout<<"Lose ";
            cout<<'\n';
    }
}