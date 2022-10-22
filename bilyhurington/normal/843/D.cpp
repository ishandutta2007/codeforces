/*
 * @Author: BilyHurington
 * @Date: 2020-07-25 13:39:24
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-07-25 16:05:39
 */ 
#include<bits/stdc++.h>
using namespace std;
int n,m,q;
pair<int,int> ed[100010];
vector<pair<int,int> > v[100010];
void Dijkstra(long long *dis){
    for(int i=1;i<=n;i++) dis[i]=1e18;
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
    dis[1]=0;pq.push(make_pair(dis[1],1));
    while(!pq.empty()){
        int x=pq.top().second;pq.pop();
        for(int i=0;i<v[x].size();i++){
            int to=v[x][i].first;
            if(dis[to]>dis[x]+v[x][i].second){
                dis[to]=dis[x]+v[x][i].second;
                pq.push(make_pair(dis[to],to));
            }
        }
    }
}
vector<int> tong[100010];
void BFS(long long *dis){
    for(int i=1;i<=n;i++) dis[i]=1e18;
    for(int i=0;i<=n;i++) vector<int>().swap(tong[i]);
    dis[1]=0;tong[0].push_back(1);
    for(int i=0;i<=n;i++){
        for(int j=0;j<tong[i].size();j++){
            if(dis[tong[i][j]]<i) continue;
            int x=tong[i][j];
            for(int k=0;k<v[x].size();k++){
                if(dis[v[x][k].first]>dis[x]+v[x][k].second){
                    dis[v[x][k].first]=dis[x]+v[x][k].second;
                    if(dis[v[x][k].first]<=n) tong[dis[v[x][k].first]].push_back(v[x][k].first);
                }
            }
        }
    }
    // printf("DIS:");
    // for(int i=1;i<=n;i++) printf("%d ",dis[i]);printf("\n");
}
long long dis[100010],dis2[100010];
int main(){
    scanf("%d %d %d",&n,&m,&q);
    int x,y,z;
    for(int i=1;i<=m;i++){
        scanf("%d %d %d",&x,&y,&z);
        v[x].push_back(make_pair(y,z));
        ed[i]=make_pair(x,v[x].size()-1);
    }
    Dijkstra(dis);
    // for(int i=1;i<=n;i++) printf("%d ",dis[i]);printf("\n");
    for(int i=1;i<=n;i++){
        for(int j=0;j<v[i].size();j++){
            v[i][j].second=dis[i]+v[i][j].second-dis[v[i][j].first];
        }
    }
    // for(int i=1;i<=m;i++) printf("%d ",v[ed[i].first][ed[i].second].second);printf("\n");
    int opt,c;
    while(q--){
        scanf("%d %d",&opt,&c);
        if(opt==1) printf("%lld\n",dis[c]>1e17?-1:dis[c]);
        else{
            for(int j=1;j<=c;j++){
                scanf("%d",&x);
                v[ed[x].first][ed[x].second].second++;
                // printf("%d %d\n",ed[x].first,ed[x].second);
            }
            BFS(dis2);
            // for(int i=1;i<=n;i++) printf("%lld ",dis2[i]);printf("\n");
            for(int i=1;i<=n;i++){
                if(dis2[i]<1e17) dis[i]+=dis2[i];
            }
            for(int i=1;i<=n;i++){
                for(int j=0;j<v[i].size();j++){
                    v[i][j].second=dis2[i]+v[i][j].second-dis2[v[i][j].first];
                }
            }
            // for(int i=1;i<=m;i++) printf("%d ",v[ed[i].first][ed[i].second].second);printf("\n");
        }
    }
    return 0;
}