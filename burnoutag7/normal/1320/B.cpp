#include<bits/stdc++.h>
using namespace std;

int n,m,k,mn,mx;
int p[200005];
int d[200005];
bool sing[200005];
vector<int> g[200005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[b].push_back(a);
    }
    cin>>k;
    for(int i=1;i<=k;i++){
        cin>>p[i];
    }
    memset(d,-1,sizeof(d));
    {
        queue<int> q;
        q.push(p[k]);
        d[p[k]]=0;
        while(!q.empty()){
            int x=q.front();
            q.pop();
            for(int i=0;i<g[x].size();i++){
                int &y=g[x][i];
                if(d[y]==-1){
                    d[y]=d[x]+1;
                    sing[y]=1;
                    q.push(y);
                }else if(d[y]==d[x]+1){
                    sing[y]=0;
                }
            }
        }
    }
    for(int i=1;i<k;i++){
        mn+=(d[p[i+1]]+1!=d[p[i]]);
        mx+=(d[p[i+1]]+1!=d[p[i]]||!sing[p[i]]);
    }
    cout<<mn<<' '<<mx<<endl;

    return 0;
}