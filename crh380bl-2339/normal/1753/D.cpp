#include<bits/stdc++.h>
using namespace std;
#define N 300105
#define PII pair<long long, int>
string s[N];
const long long INF = 1LL<<61LL;
int n,m;
int get_id(int i,int j){
    if(i<0||j<0||i>=n||j>=m)return -1;
    if(s[i][j]=='#')return -1;
    if(s[i][j]=='.')return 1;
    return i*m+j+2;
}
int dx1[4]={0,-2,0,2};
int dy1[4]={2,0,-2,0};

int dx2[4]={1,-1,1,-1};
int dy2[4]={1,-1,-1,1};
struct edge{
    int to,w;
    edge(){};
    edge(int _a, int _b){
        to=_a;w=_b;
    }
};
vector<edge>e[N];
priority_queue<PII, vector<PII>, greater<PII> > Q;
long long dis[N];
bool vis[N];
void add(int x,int y,int w){
    //printf("[%d, %d]%d\n",x,y,w);
    e[x].emplace_back(y,w);
}
// void add2(int x,int y,int w){
//     add(x,y,w);
//     add(y,x,w);
// }
void work(){
    int p,q,i,j,k;
    scanf("%d%d",&n,&m);
    scanf("%d%d",&p,&q);
    for(i=0;i<n;++i){
        cin>>s[i];
    }
    for(i=0;i<n;++i){
        for(j=0;j<m;++j){
            int id1=get_id(i,j);
            if(id1==-1)continue;
            dis[id1] = INF;
            int id2;
            if(j<m-1 && s[i][j]=='L' && s[i][j+1]=='R'){
                id2 = get_id(i, j+2);
                if(id2!=-1){
                    add(id2,id1,q);
                    //add2(id1,id2,q);
                }
                id2 = get_id(i, j-1);
                int id3=get_id(i, j+1);
                if(id2!=-1 && id3!=-1){
                    add(id2,id3,q);
                }                
            }
            if(i<n-1 && s[i][j]=='U' && s[i+1][j]=='D'){
                id2 = get_id(i+2, j);
                if(id2!=-1){
                    add(id2,id1,q);
                }
                id2 = get_id(i-1, j);
                int id3=get_id(i+1,j);
                if(id2!=-1 && id3!=-1){
                    add(id2,id3,q);
                }                
            }
            if(j<m-1 && s[i][j]=='L' && s[i][j+1]=='R'){
                int id2=get_id(i,j+1);
                int id3;
                id3=get_id(i-1,j);
                if(id3!=-1){
                    add(id3,id2,p);
                }
                id3=get_id(i+1,j);
                if(id3!=-1){
                    add(id3,id2,p);
                }
                id3=get_id(i+1,j+1);
                if(id3!=-1){
                    add(id3,id1,p);
                }
                id3=get_id(i-1,j+1);
                if(id3!=-1){
                    add(id3,id1,p);
                }
            }
            if(i<n-1 && s[i][j]=='U' && s[i+1][j]=='D'){
                id2 = get_id(i+1, j);
                int id3;
                id3=get_id(i,j-1);
                if(id3!=-1)add(id3,id2,p);
                id3=get_id(i,j+1);
                if(id3!=-1)add(id3,id2,p);
                id3=get_id(i+1,j-1);         
                if(id3!=-1)add(id3,id1,p);
                id3=get_id(i+1,j+1);
                if(id3!=-1)add(id3,id1,p);
            }
        }
    }
    dis[1]=0;
    Q.emplace(dis[1], 1);
    while(!Q.empty()){
        auto h=Q.top();
        Q.pop();
        if(vis[h.second])continue;
        vis[h.second]=1;
        for(auto p:e[h.second]){
            int y=p.to,w=p.w;
            if(dis[y] > dis[h.second] + w){
                dis[y] = dis[h.second] + w;
                Q.emplace(dis[y], y);
            }
        }
    }
    long long ans=INF;
    for(i=0;i<n;++i){
        for(j=0;j<m;++j){
            int id1=get_id(i,j);
            if(id1==-1)continue;
            //printf("%d %lld\n",id1,dis[id1]);
            int id2=get_id(i+1, j);
            int id3=get_id(i,j+1);
            if(id2!=-1){
                ans=min(ans, dis[id1]+dis[id2]);
            }
            if(id3!=-1){
                ans=min(ans, dis[id1]+dis[id3]);
            }
        }
    }
    if(ans>=INF)ans=-1;
    printf("%lld\n",ans);
}
int main(){
    int T;
    T=1;
    while(T--){
        work();
    }
    return 0;
}