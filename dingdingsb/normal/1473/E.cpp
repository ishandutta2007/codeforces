#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=800010;
vector<pair<int,int>>e[N];
int dis[N];
bool vis[N];
int n,m;
struct node{
    int dis,pos;
    bool operator<(const node &x)const{return x.dis<dis;}
};
std::priority_queue<node> q;
inline void dij(){
    dis[1]=0;
    q.push({0,1});
    while(!q.empty()){
        node tmp=q.top();q.pop();
        int x=tmp.pos,d=tmp.dis;
        if(vis[x])continue;
        vis[x]=1;
        for(auto E:e[x]){
            int y=E.first,w=E.second;
            if(dis[y]>dis[x]+w){
                dis[y]=dis[x]+w;
                if(!vis[y])
                    q.push({dis[y],y});
            }
        }
    }
}
void add(int u,int v,int w){
	e[u].push_back({v,w});
}
#define id1(a) (a)
#define id2(a) ((a)+n)
#define id3(a) ((a)+n*2)
#define id4(a) ((a)+n*3)
signed main(){
    scanf("%lld%lld",&n,&m);
    memset(dis,0x3f,sizeof dis);
    for(int i=1,u,v,w;i<=m;i++){
		scanf("%lld%lld%lld",&u,&v,&w);
    	for(int j=0;j<4;j++)add(u+n*j,v+n*j,w);
		add(id1(u),id2(v),0);
		add(id1(u),id3(v),2*w);
		add(id2(u),id4(v),2*w);
		add(id3(u),id4(v),0);
		swap(u,v);
		for(int j=0;j<4;j++)add(u+n*j,v+n*j,w);
		add(id1(u),id2(v),0);
		add(id1(u),id3(v),2*w);
		add(id2(u),id4(v),2*w);
		add(id3(u),id4(v),0);
	}
	dij();
	for(int i=2;i<=n;i++)
		cout<<min(dis[id1(i)],dis[id4(i)])<<" ";
	//cout<<"fuck you";
}