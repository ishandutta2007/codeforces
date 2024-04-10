#include<bits/stdc++.h>
//dengyaotriangle!
using namespace std;

const int maxn=100005;

int n,q,s;
vector<pair<int,int> > adj[maxn<<4];
int c1;
int c[maxn<<4][2];
long long dis[maxn<<4];
priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > > pq;

int bt1(int l,int r){
    int cur=++c1;
    if(l==r){
        adj[cur].push_back(make_pair(l,0));
    }else{
        c[cur][0]=bt1(l,(l+r)>>1);
        c[cur][1]=bt1(((l+r)>>1)+1,r);
        adj[cur].push_back(make_pair(c[cur][0],0));
        adj[cur].push_back(make_pair(c[cur][1],0));
    }
    return cur;
}

int bt2(int l,int r){
    int cur=++c1;
    if(l==r){
        adj[l].push_back(make_pair(cur,0));
    }else{
        c[cur][0]=bt2(l,(l+r)>>1);
        c[cur][1]=bt2(((l+r)>>1)+1,r);
        adj[c[cur][0]].push_back(make_pair(cur,0));
        adj[c[cur][1]].push_back(make_pair(cur,0));
    }
    return cur;
}

void ade1(int rt,int cl,int cr,int l,int r,int v,int w){
    int cm=(cl+cr)>>1;
    if(cl==l&&cr==r){
        adj[v].push_back(make_pair(rt,w));
        return;
    }else if(r<=cm)ade1(c[rt][0],cl,cm,l,r,v,w);
    else if(l>cm)ade1(c[rt][1],cm+1,cr,l,r,v,w);
    else{
        ade1(c[rt][0],cl,cm,l,cm,v,w);
        ade1(c[rt][1],cm+1,cr,cm+1,r,v,w);
    }
}
void ade2(int rt,int cl,int cr,int l,int r,int v,int w){
    int cm=(cl+cr)>>1;
    if(cl==l&&cr==r){
        adj[rt].push_back(make_pair(v,w));
        return ;
    }else if(r<=cm)ade2(c[rt][0],cl,cm,l,r,v,w);
    else if(l>cm)ade2(c[rt][1],cm+1,cr,l,r,v,w);
    else{
        ade2(c[rt][0],cl,cm,l,cm,v,w);
        ade2(c[rt][1],cm+1,cr,cm+1,r,v,w);
    }
}
void dijkstra(int s){
    memset(dis,-1,sizeof(dis));
    pq.push(make_pair(0,s));
    while(!pq.empty()){
        int cu=pq.top().second;
        long long cw=pq.top().first;
        pq.pop();
        if(dis[cu]!=-1)continue;
        dis[cu]=cw;
        for(int i=0;i<adj[cu].size();i++){
            int v=adj[cu][i].first;
            long long w=adj[cu][i].second+cw;
            if(dis[v]==-1)pq.push(make_pair(w,v));
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>q>>s;
    c1=n;
    int rt1=bt1(1,n);
    int rt2=bt2(1,n);
    while(q--){
        int op,u,v,l,r,w;
        cin>>op;
        if(op==1){
            cin>>u>>v>>w;
            adj[u].push_back(make_pair(v,w));
        }else if(op==2){
            cin>>u>>l>>r>>w;
            ade1(rt1,1,n,l,r,u,w);
        }else{
            cin>>u>>l>>r>>w;
            ade2(rt2,1,n,l,r,u,w);
        }
    }
    dijkstra(s);
    for(int i=1;i<=n;i++)cout<<dis[i]<<' ';
    return 0;
}