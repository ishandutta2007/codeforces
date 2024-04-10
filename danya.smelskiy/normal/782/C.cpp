#include <bits/stdc++.h>
using namespace std;

vector<int> v[200005];
int color[200005];
int n;
int pred[200005];
int x,y;
int ans;
bool used[200005];
void dfs(int x,int p,int c){
    color[x]=c;
    if (used[c]==false) {
        used[c]=true;
        ++ans;
    }
    pred[x]=p;
    int last=1;
    int y=color[pred[x]];
    for (int i=0;i<v[x].size();++i){
        int to=v[x][i];
        if (to==p) continue;
        while (true) {
            if (last!=c && last!=y) break;
            ++last;
        }
        dfs(to,x,last);
        ++last;
    }

}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=1;i<n;++i){
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1,0,1);
    cout<<ans<<'\n';
    for (int i=1;i<=n;++i)
        cout<<color[i]<<" ";
}