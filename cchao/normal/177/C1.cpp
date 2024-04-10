#include <iostream>
#include <vector>
#include <set>
#include <deque>
#include <queue>
#include <cstring>
using namespace std;

int n,l,d,maxi=0;
int adj[2010][2010]={{0}};
int vis[2010]={0};
void bfs(int x){
    set<int> res;
    set<int> hate;
    queue<int> q;
    q.push(x);
    res.insert(x);
    vis[x]=1;
    while(!q.empty()){
        int t=q.front();
        q.pop();
        for(int k=1;k<=n;k++){
            if(adj[t][k]==-1){
                if(res.count(k)>0) return;
                hate.insert(k);
            }
            if(adj[t][k]==1){
                if(hate.count(k) > 0){vis[k]=1;return;}
                else if(!vis[k]){
                    q.push(k);
                    res.insert(k);
                    vis[k]=1;
                }
            }
        }
    }
    if(res.size() > maxi) maxi=res.size();

    int k;
}
int main(){
    cin >> n >> l;
    int j,k,a,b;
    for(j=0;j<l;j++){
        cin >> a >> b;
        adj[a][b]=adj[b][a]=1;
    }
    cin >> d;
    for(j=0;j<d;j++){
        cin >> a >> b;
        adj[a][b]=adj[b][a]=-1;
    }
    //cout << "----" << endl;
    for(k=1;k<=n;k++)
        if(vis[k]==0) bfs(k);
    cout << maxi << endl;
    return 0;
}