#include <bits/stdc++.h>
#define int long long
#define mod 10000000000000007
using namespace std;
int n,m,s,t,k,p[200005],u[200005],v[200005],first[200005],nxt[200005],tot;
inline void add(int i){
    nxt[i]=first[u[i]],first[u[i]]=i;
    return;
}
struct node{
    int id,dis;
    bool operator <(const node &x)const{
        return x.dis<dis;
    }
};
priority_queue <node>h;
int dis[200005][2],num[200005][2];
inline void getdis(int s,int now){
    for (int i=0;i<=n;i++)dis[i][now]=1e9;
    dis[s][now]=0;num[s][now]=1;
    while(!h.empty())h.pop();
    h.push(node{s,0});
    while(!h.empty()){
        node c=h.top();
        h.pop();
        for (int i=first[c.id];i;i=nxt[i]){
            if (dis[v[i]][now]>c.dis+1){
                dis[v[i]][now]=c.dis+1;
                num[v[i]][now]=num[u[i]][now];
                h.push(node{v[i],dis[v[i]][now]});
            }
            else if (dis[v[i]][now]==c.dis+1)num[v[i]][now]+=num[u[i]][now],num[v[i]][now]%=mod;
        }
    }
    return;
}
signed main(){
	cin>>n>>m;
    for (int i=1;i<=m;i++){
        scanf("%d%d",&u[i],&v[i]);
        add(i);
    }
    cin>>k;
    for (int i=1;i<=k;i++)scanf("%d",&p[i]);
    s=p[1],t=p[k];
    getdis(s,0);
    memset(first,0,sizeof(first));
    memset(nxt,0,sizeof(nxt));
    for (int i=1;i<=m;i++){
        swap(u[i],v[i]);
        add(i);
    }
    getdis(t,1);
    int ans1=0,ans2=0;
    for (int i=2;i<=k;i++){
        if (1+dis[p[i]][1]!=dis[p[i-1]][1])ans1++,ans2++;
        else if (num[p[i-1]][1]!=1&&num[p[i-1]][1]!=num[p[i]][1])ans2++;
    }
    cout<<ans1<<' '<<ans2<<endl;
    return 0;
}