#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
int ct;
struct dij {
    struct edge {
        int ed, l;
    };
    struct node {
        long long num, d;
        friend bool operator<(node a, node b) {
            return a.d > b.d;
        }
    };
    long long dis[1000005];
    int visit[1000005],n;
    vector<edge> v[1000005];
    priority_queue<node> q;
    void add_edge(int x,int y,int w,int type=0){
        if(type) swap(x,y),x+=ct,y+=ct;
        v[x].push_back(edge{y,w});
    }
    void solve(int st) {
        for(int i=1;i<=n;i++) dis[i]=LLONG_MAX/10;
        dis[st]=0;
        q.push(node{st,0});
        while (!q.empty()) {
            long long x = q.top().num;
            q.pop();
            if (visit[x]) continue;
            visit[x] = 1;
            for (int i = 0; i < v[x].size(); i++) {
                if (visit[v[x][i].ed]) continue;
                if (dis[v[x][i].ed] > dis[x] + v[x][i].l) {
                    dis[v[x][i].ed] = dis[x] + v[x][i].l;
                    node p;
                    p.num = v[x][i].ed;
                    p.d = dis[v[x][i].ed];
                    q.push(p);
                }
            }
        }
    }
}G;
vector <char> v[300005];
vector <int> c[300005];
int main(){
    int T = 1, kase = 0;
    //cin >> T;
    while (T--){
        int n,m,p,q;
        cin>>n>>m;
        for(int i=1;i<=n;i++) v[i].resize(m+5),c[i].resize(m+5);
        cin>>p>>q;
        G.n=2*n*m+2;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++){
                v[i][j]='?';
                while(v[i][j]!='U'&&v[i][j]!='L'&&v[i][j]!='D'&&v[i][j]!='R'&&v[i][j]!='.'&&v[i][j]!='#') scanf("%c",&v[i][j]);
                c[i][j]=(i+j)%2;
            }
        ct=n*m;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++){
                if(v[i][j]=='#') continue;
                if(i-1>0&&j+1<=m&&(v[i-1][j]=='L'||v[i][j+1]=='D')) G.add_edge((i-1)*m+j,(i-2)*m+j+1,p);
                if(i+1<=n&&j+1<=m&&(v[i+1][j]=='L'||v[i][j+1]=='U')) G.add_edge((i-1)*m+j,i*m+j+1,p);
                if(i+1<=n&&j-1>0&&(v[i+1][j]=='R'||v[i][j-1]=='U')) G.add_edge((i-1)*m+j,i*m+j-1,p);
                if(i-1>0&&j-1>0&&(v[i-1][j]=='R'||v[i][j-1]=='D')) G.add_edge((i-1)*m+j,(i-2)*m+j-1,p);
                if(j+2<=m&&v[i][j+1]=='L') G.add_edge((i-1)*m+j,(i-1)*m+j+2,q);
                if(i+2<=n&&v[i+1][j]=='U') G.add_edge((i-1)*m+j,(i+1)*m+j,q);
                if(j-2>0&&v[i][j-1]=='R') G.add_edge((i-1)*m+j,(i-1)*m+j-2,q);
                if(i-2>0&&v[i-1][j]=='D') G.add_edge((i-1)*m+j,(i-3)*m+j,q);
                if(i-1>0&&j+1<=m&&(v[i-1][j]=='L'||v[i][j+1]=='D')) G.add_edge((i-1)*m+j,(i-2)*m+j+1,p,1);
                if(i+1<=n&&j+1<=m&&(v[i+1][j]=='L'||v[i][j+1]=='U')) G.add_edge((i-1)*m+j,i*m+j+1,p,1);
                if(i+1<=n&&j-1>0&&(v[i+1][j]=='R'||v[i][j-1]=='U')) G.add_edge((i-1)*m+j,i*m+j-1,p,1);
                if(i-1>0&&j-1>0&&(v[i-1][j]=='R'||v[i][j-1]=='D')) G.add_edge((i-1)*m+j,(i-2)*m+j-1,p,1);
                if(j+2<=m&&v[i][j+1]=='L') G.add_edge((i-1)*m+j,(i-1)*m+j+2,q,1);
                if(i+2<=n&&v[i+1][j]=='U') G.add_edge((i-1)*m+j,(i+1)*m+j,q,1);
                if(j-2>0&&v[i][j-1]=='R') G.add_edge((i-1)*m+j,(i-1)*m+j-2,q,1);
                if(i-2>0&&v[i-1][j]=='D') G.add_edge((i-1)*m+j,(i-3)*m+j,q,1);
                if(v[i][j]=='.'){
                    if(c[i][j]) G.add_edge((i-1)*m+j+n*m,2*n*m+2,0);
                    else G.add_edge(2*n*m+1,(i-1)*m+j,0);
                }
                if(i+1<=n&&v[i+1][j]!='#'){
                    if(c[i][j]==0) G.add_edge((i-1)*m+j,i*m+j+n*m,0);
                    else G.add_edge(i*m+j,(i-1)*m+j+n*m,0);
                }
                if(j+1<=m&&v[i][j+1]!='#'){
                    if(c[i][j]==0) G.add_edge((i-1)*m+j,(i-1)*m+j+1+n*m,0);
                    else G.add_edge((i-1)*m+j+1,(i-1)*m+j+n*m,0);
                }
            }
        G.solve(2*n*m+1);
        if(G.dis[2*n*m+2]==LLONG_MAX/10) puts("-1");
        else printf("%lld\n",G.dis[2*n*m+2]);
    }
    return 0;
}