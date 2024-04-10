#include <bits/stdc++.h>
using namespace std;

int n;
int x,y;
vector<int> v[100005];
long double ans=0;
void dfs(int x,int y,long double d,long double zz){
    if (v[x].size()==1 && x!=1) ans+=d*zz;
    long double kol=0;
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        if (to==y) continue;
        ++kol;
    }
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        if (to==y) continue;
        dfs(to,x,d+1,zz*(long double)(1)/kol);
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<n;++i) {
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    if (n==1) {
        cout<<0;
        return 0;
    }
    dfs(1,-1,0,1);
    cout<<fixed<<setprecision(6)<<ans;
}