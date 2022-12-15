#include <bits/stdc++.h>
using namespace std;

int T,N,x,y,ans[100005],B[100005];
vector<int> G[100010];
class cmp{
    public:
        int operator()(int u,int v){
            return G[u].size()<G[v].size();
        }
};
int spclr;
int main(){
    scanf("%d", &T);
    while(T--){
        scanf("%d%d%d",&N,&x,&y);y-=x;
        for(int i=1;i<=N+1;i++) G[i].clear();
        for(int i=1;i<=N;i++) scanf("%d",&B[i]),G[B[i]].push_back(i);
        for(int i=N+1;i;i--)
            if(!G[i].size()){
                for(int j=1;j<=N;j++) ans[j]=998244353;
                spclr=i;
                break;
            }
        int u,v;
        u=1;
        for(int i=2;i<=N+1;i++) if(G[i].size()>=G[u].size()) u=i;
        v=(u==1)?2:1;
        while ((v<=N&&G[v].size()==0)||u==v) v++;
        priority_queue<int,vector<int>,cmp> q;
        for(int i=1;i<=N+1;i++) q.push(i);
        if((y&1)&&G[u].size()+G[v].size()!=N&&y>=3){
            int a=q.top();q.pop();
            int b=q.top();q.pop();
            int c=q.top();q.pop();
            ans[G[a].back()]=b;G[a].pop_back();
            ans[G[b].back()]=c;G[b].pop_back();
            ans[G[c].back()]=a;G[c].pop_back();
            q.push(a);
            q.push(b);
            q.push(c);
            y-=3;
        }
        int did=1;
        for(int i=1;i<=y;i+=2){
            int a=q.top();q.pop();
            int b=q.top();q.pop();
            if(G[a].empty()||G[b].empty()){printf("NO\n");goto lbl;}
            ans[G[a].back()]=b;G[a].pop_back();
            ans[G[b].back()]=(i==y)?998244352:a;G[b].pop_back();
            q.push(a),q.push(b);
        }
        for(int i=1;i<=x;i++){
            while(did<=N&&ans[did]!=998244353) did++;
            ans[did]=B[did];
        }
        if(did==N+1){printf("NO\n");goto lbl;}
        printf("YES\n");
        for(int i=1;i<=N;i++) printf("%d ",ans[i]==998244353||ans[i]==998244352?spclr:ans[i]);
        printf("\n");
        lbl:;
    }
}