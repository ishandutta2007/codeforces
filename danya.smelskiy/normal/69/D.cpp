#include <bits/stdc++.h>
using namespace std;

int x,y,n,d;
bool used[1000][1000];
bool ans[1000][1000];
int xx[100],yy[100];
inline bool f(int x,int y){
    return (x*x+y*y<=d*d);
}
bool dfs(int x,int y){
    if (!f(x,y)) return false;
    if (used[x+300][y+300]) return ans[x+300][y+300];
    used[x+300][y+300]=true;
    for (int i=1;i<=n;++i) if (f(x+xx[i],y+yy[i])){
        ans[x+300][y+300]|=(1-dfs(x+xx[i],y+yy[i]));
    }
    return ans[x+300][y+300];
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>x>>y>>n>>d;
    for (int i=1;i<=n;++i)
        cin>>xx[i]>>yy[i];
    if (dfs(x,y)) cout<<"Anton";
    else cout<<"Dasha";
}