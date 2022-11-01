#include <bits/stdc++.h>
#include <queue>
#include <vector>
#include <map>

using namespace std;

#define FOR(i,x,y)  for(int i = x;i < y;++ i)
#define IFOR(i,x,y) for(int i = x;i > y;-- i)
#define pb  push_back
#define mp  make_pair
#define fi  first
#define se  second
typedef long long   LL;
typedef pair<int,int>   PII;
typedef vector<int> VI;
typedef map<int,int>    MP;

const int maxn = 100010;

bool vis[maxn<<1];
int n,m,a[maxn],b[maxn],c[maxn],d[maxn];
MP mat;
set <PII> cc[maxn<<1];
VI vx;

int lowbit(int x)   {return x&-x;}

void modify(int x,PII val){
    while(x <= m){
        cc[x].insert(val);
        x += lowbit(x);
    }
}

VI query(int x,int y){
    VI tem;
    while(x){
        set <PII> :: iterator last = cc[x].upper_bound(mp(y,maxn));
        set <PII> :: iterator it;
        for(it = cc[x].begin();it != last;it ++)    tem.pb(it->se);
        cc[x].erase(cc[x].begin(),last);
        x -= lowbit(x);
    }
    return tem;
}

int dist[maxn],fa[maxn],path[maxn];

void bfs(){
    memset(fa,-1,sizeof(fa));
    memset(dist,-1,sizeof(dist));
    //printf("%d\n",mat[0]);
    VI u = query(mat[0],0);
    queue <int> q;
    /*
    FOR(i,0,(int)u.size()){
        printf("%d ",u[i]);
    }
    printf("\n");
    */
    FOR(i,0,(int)u.size())  q.push(u[i]),vis[u[i]] = true,dist[u[i]] = 1;
    while(!q.empty()){
        int id = q.front(); q.pop();
        //printf("id: %d __",id);
        VI v = query(mat[c[id]],d[id]);
        FOR(i,0,(int)v.size()){
            //printf("%d ",v[i]);
            if(vis[v[i]])   continue;
            vis[v[i]] = true;
            dist[v[i]] = dist[id] + 1;
            fa[v[i]] = id;
            q.push(v[i]);
        }
        //printf("\n");
    }
}

int main(){
    //freopen("cin.txt","r",stdin);
    while(~scanf("%d",&n)){
        FOR(i,0,n)  scanf("%d%d%d%d",a+i,b+i,c+i,d+i),vx.pb(a[i]),vx.pb(c[i]);
        sort(vx.begin(),vx.end());

        //FOR(i,0,n+n)  printf("%d ",vx[i]);    printf("\n");

        m = 0;  mat[vx[0]] = ++ m;
        FOR(i,1,(int)vx.size()){
            if(vx[i] > vx[i-1]) mat[vx[i]] = ++m;
        }
        FOR(i,0,m+1)    cc[i].clear();
        FOR(i,0,n)  modify(mat[a[i]],mp(b[i],i));
        //FOR(i,0,n)    printf("%d %d\n",mat[a[i]],b[i]);
        bfs();
        printf("%d\n",dist[n-1]);
        if(dist[n-1] == -1){
            continue;
        }
        else{
            int cnt = 0;
            int u = n-1;
            while(u != -1){
                path[cnt++] = u+1;
                u = fa[u];
            }
            printf("%d",path[cnt-1]);
            IFOR(i,cnt-2,-1){
                printf(" %d",path[i]);
            }
            printf("\n");
        }
    }
    return 0;
}