#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
int n;
struct seg_tree{
    long long k[400005],b[400005],lv[400005],rv[400005],mv[400005];
    void clear(){
        for(int i=1;i<=n*4;i++) k[i]=0,b[i]=lv[i]=rv[i]=mv[i]=LLONG_MAX/5;
    }
    void pushdown(int node,int l,int r){
        if(k[node]==0) return;
        k[node*2]=k[node*2+1]=k[node];
        b[node*2]=b[node*2+1]=b[node];
        k[node]=0,b[node]=LLONG_MAX/5;
        int mid=(l+r)>>1;
        lv[node*2]=lv[node],mv[node*2]=k[node*2]*((l+mid)/2)+b[node*2],rv[node*2]=mv[node];
        lv[node*2+1]=k[node*2+1]*(mid+1)+b[node*2+1],mv[node*2+1]=k[node*2+1]*(((mid+1)+r)/2)+b[node*2+1],rv[node*2+1]=rv[node];
    }
    void update(int node,int l,int r,long long kk,long long bb){
        if(l==r){
            if(kk*l+bb<k[node]*l+b[node]) k[node]=kk,b[node]=bb;
            lv[node]=rv[node]=mv[node]=k[node]*l+b[node];
            return;
        }
        pushdown(node,l,r);
        int mid=(l+r)>>1;
        if(kk*mid+bb<mv[node]) k[node*2+1]=kk,b[node*2+1]=bb,lv[node*2+1]=kk*(mid+1)+bb,rv[node*2+1]=kk*r+bb,mv[node*2+1]=kk*((mid+1+r)/2)+bb,update(node*2,l,mid,kk,bb);
        else update(node*2+1,mid+1,r,kk,bb);
        lv[node]=lv[node*2],rv[node]=rv[node*2+1],mv[node]=rv[node*2];

    }
    void update(long long kk,long long bb){
        update(1,1,n,kk,bb);
    }
    long long query(int node,int l,int r,int pos){
        //cout<<l<<" "<<r<<" "<<k[node]<<" "<<b[node]<<endl;
        if(k[node]) return k[node]*pos+b[node];
        int mid=(l+r)>>1;
        if(pos<=mid) return query(node*2,l,mid,pos);
        else return query(node*2+1,mid+1,r,pos);
    }
}Tr;
vector <pair<int,int>> v[100005];
struct node{
    int x;
    long long d;
    friend bool operator <(node a,node b){
        return a.d>b.d;
    }
};
long long dis[100005][21];
int vis[100005][21];
int main() {
    int T = 1, kase = 0;
    //cin >> T;
    while (T--) {
        int m,k;
        cin>>n>>m>>k;
        for(int i=1,x,y,w;i<=m;i++){
            scanf("%d%d%d",&x,&y,&w);
            v[x].push_back({y,w}),v[y].push_back({x,w});
        }
        for(int i=1;i<=n;i++)
            for(int j=0;j<=k;j++)
                dis[i][j]=LLONG_MAX/10;
        priority_queue <node> q;
        dis[1][0]=0,q.push(node{1,0});
        while(!q.empty()){
            auto temp=q.top();
            q.pop();
            if(vis[temp.x][0]) continue;
            vis[temp.x][0]=1;
            for(auto t:v[temp.x])
                if(!vis[t.first][0]&&temp.d+t.second<dis[t.first][0])
                    dis[t.first][0]=temp.d+t.second,q.push(node{t.first,temp.d+t.second});
        }
        //for(int i=1;i<=n;i++) cout<<dis[i][0]<<" ";puts("");
        for(int i=1;i<=k;i++){
            Tr.clear();
            for(int j=1;j<=n;j++) Tr.update(-j*2,1LL*j*j+dis[j][i-1]);
            for(int j=1;j<=n;j++){
                long long val=Tr.query(1,1,n,j);
                q.push(node{j,val+1LL*j*j}),dis[j][i]=val+1LL*j*j;
                //cout<<dis[j][i]<<" ";
            }//puts("");
            while(!q.empty()){
                auto temp=q.top();
                q.pop();
                if(vis[temp.x][i]) continue;
                vis[temp.x][i]=1;
                for(auto t:v[temp.x])
                    if(!vis[t.first][i]&&temp.d+t.second<dis[t.first][i])
                        dis[t.first][i]=temp.d+t.second,q.push(node{t.first,temp.d+t.second});
            }
        }
        for(int i=1;i<=n;i++) printf("%lld ",dis[i][k]);
    }
    return 0;
}