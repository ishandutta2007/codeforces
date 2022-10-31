#include<bits/stdc++.h>
using namespace std;
const int maxn = 500;
int d[maxn*maxn];
map<int,int>id;int idcnt;
map<pair<int,int>,int>id2;int id2cnt;
pair<int,int> status[maxn*maxn];
int ans[maxn*maxn];
int first[maxn*maxn],nxt[1750000],des[1750000],tot;
int W[6];
int T,f;
queue<int>Q;
inline int get(int status,int x_){
    return status%W[x_+1]/W[x_];
}
void dfs(int dep,int rest,int val){
    if (dep==4){
        int temp = val+rest*W[4];
        if (!id.count(temp)){
            id.insert(make_pair(temp,++idcnt));
        }
        return;
    }
    for (int i=0;i<=rest;i++){
        dfs(dep+1,rest-i,val+W[dep]*i);
    }
}
inline void AE(int id1,int id2){
    tot++;
    des[tot] =id2;
    nxt[tot] = first[id1];
    first[id1] = tot;
    d[id2]++;
}
void addEdge(int fi,int se,int idd){
    for (int i=1;i<=4;i++){
        for (int j=1;j<=4;j++){
            int f = get(fi,i);
            int s = get(se,j);
            if (f>0&&s>0){
                AE(id2[make_pair(se,fi-W[i]+W[(i+j)%5])],idd);
            }
        }
    }
}
void search(){
    for (int i=1;i<=id2cnt;i++){
        if (d[i]==0){
            if (status[i].first==8){
                ans[i] =1;
            }else{
                ans[i] =-1;
            }
            Q.push(i);
        }
    }
    while (!Q.empty()){
        int q = Q.front();
        Q.pop();
        if (ans[q]==1){
            for (int t = first[q];t;t=nxt[t]){
                int v = des[t];
                d[v]--;
                if (d[v]==0&&ans[v]==0){
                    ans[v]=-1;
                    Q.push(v);
                }

            }
        }else{
            for (int t = first[q];t;t=nxt[t]){
                int v = des[t];
                d[v]--;
                if (ans[v]==0){
                    ans[v]=1;
                    Q.push(v);
                }
            }
        }
    }
}
void init(){
    W[0]=1;
    for (int i=1;i<=5;i++)W[i] =W[i-1]*10;
    dfs(0,8,0);
    for (pair<int,int>fi :id){
        for (pair<int,int>se:id){
            id2.insert(make_pair(make_pair(fi.first,se.first),++id2cnt));
            status[id2cnt] = make_pair(fi.first,se.first);
        }
    }
    memset(d,0,sizeof d);
    for (pair<pair<int,int>,int>e:id2){
        addEdge(e.first.first,e.first.second,e.second);
    }
    search();
}
void solve(){
    scanf("%d",&f);
    int ast=0,bst=0;
    for (int i=0;i<8;i++){
        int t;
        scanf("%d",&t);
        ast+=W[t];
    }
    for (int i=0;i<8;i++){
        int t;
        scanf("%d",&t);
        bst+=W[t];
    }
    if (f){
        int res = ans[id2[make_pair(bst,ast)]];
        if (res==1){
            printf("Bob\n");
        }else if (res==-1){
            printf("Alice\n");
        }else{
            printf("Deal\n");
        }
    }else{
        int res = ans[id2[make_pair(ast,bst)]];
        if (res==1){
            printf("Alice\n");
        }else if (res==-1){
            printf("Bob\n");
        }else{
            printf("Deal\n");
        }
    }
}
int main(){
    init();
    scanf("%d",&T);
    while (T--){
        solve();
    }
    return 0;
}