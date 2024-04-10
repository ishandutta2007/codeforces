#include<bits/stdc++.h>
using namespace std;

int n,ans;
vector<int> g[200005];
pair<int,int> e[200005];
int dis[3][200005];

void bfs(int st,int *d){
    queue<int> q;
    q.push(st);
    d[st]=0;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(int i=0;i<g[x].size();i++){
            int &y=g[x][i];
            if(d[y]>d[x]){
                d[y]=d[x]+1;
                q.push(y);
            }
        }
    }
}

void bfs(vector<int> &v,int *d){
    queue<int> q;
    for(int i=0;i<v.size();i++){
        q.push(v[i]);
        d[v[i]]=0;
    }
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(int i=0;i<g[x].size();i++){
            int &y=g[x][i];
            if(d[y]>d[x]){
                d[y]=d[x]+1;
                q.push(y);
            }
        }
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
        e[i]=make_pair(a,b);
    }

    bfs(1,dis[0]);
    int F=1;
    for(int i=1;i<=n;i++){
        if(dis[0][i]>dis[0][F])F=i;
    }

    bfs(F,dis[1]);
    int S=1;while(S==F)S++;
    for(int i=1;i<=n;i++){
        if(dis[1][i]>dis[1][S]&&i!=F)S=i;
    }

    {
        vector<int> v;
        int x=S;
        while(x!=F){
            v.push_back(x);
            for(int i=0;i<g[x].size();i++){
                int &y=g[x][i];
                if(dis[1][y]<dis[1][x]){
                    x=y;break;
                }
            }
        }
        v.push_back(F);
        bfs(v,dis[2]);
    }
    int T=1;while(T==F||T==S)T++;
    for(int i=1;i<=n;i++){
        if(dis[2][i]>dis[2][T]&&i!=F&&i!=S)T=i;
    }

    memset(dis,0x3f,sizeof(dis));
    bfs(F,dis[0]);
    bfs(S,dis[1]);
    bfs(T,dis[2]);

    for(int i=1;i<n;i++){
        pair<int,int> &E=e[i];
        bool f=false;
        if(dis[0][S]==dis[0][E.first]+1+dis[1][E.second])f=true;
        if(dis[0][T]==dis[0][E.first]+1+dis[2][E.second])f=true;
        if(dis[1][F]==dis[1][E.first]+1+dis[0][E.second])f=true;
        if(dis[1][T]==dis[1][E.first]+1+dis[2][E.second])f=true;
        if(dis[2][F]==dis[2][E.first]+1+dis[0][E.second])f=true;
        if(dis[2][S]==dis[2][E.first]+1+dis[1][E.second])f=true;
        swap(E.first,E.second);
        if(dis[0][S]==dis[0][E.first]+1+dis[1][E.second])f=true;
        if(dis[0][T]==dis[0][E.first]+1+dis[2][E.second])f=true;
        if(dis[1][F]==dis[1][E.first]+1+dis[0][E.second])f=true;
        if(dis[1][T]==dis[1][E.first]+1+dis[2][E.second])f=true;
        if(dis[2][F]==dis[2][E.first]+1+dis[0][E.second])f=true;
        if(dis[2][S]==dis[2][E.first]+1+dis[1][E.second])f=true;
        ans+=f;
    }
    cout<<ans<<endl<<F<<' '<<S<<' '<<T<<endl;

    return 0;
}