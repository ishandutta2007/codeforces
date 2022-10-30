#include <bits/stdc++.h>
using namespace std;


int pred[1000005];
int ans[1000005];
bool used[1000005];
vector<int> v[1000005];
int n,m;
int x,y;

void dfs(int x,int y,int z){
    ans[x]=z;
    pred[x]=y;
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        if (to==y) continue;
        dfs(to,x,min(z,to));
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<n;++i) {
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    cin>>x>>y;
    y=(y)%n+1;
    used[y]=true;
    dfs(y,-1,y);
    int localmin=y;
    int last=0;
    for (int i=1;i<m;++i) {
        cin>>x>>y;
        y=(y+last)%n+1;
        if (x==1) {
            for (int j=y;used[j]==false;j=pred[j]) {
                localmin=min(localmin,j);
                used[j]=true;
            }
        } else{
            int res=min(ans[y],localmin);
            cout<<res<<'\n';
            last=res;
        }
    }
}