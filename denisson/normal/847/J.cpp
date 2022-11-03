#include <bits/stdc++.h>
      
using namespace std;
      
typedef long long ll;
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()

int nn, mm;

struct Dinic{ //with scaling
    struct edge{
        int to, flow, cap;
    };

    const static int N = 20007; //count of vertexes
    
    vector<edge> e;
    vector<int> g[N + 7];
    int dp[N + 7];
    int ptr[N + 7];

    void clear(){
        for (int i = 0; i < N + 7; i++) g[i].clear();
        e.clear();
    }

    void addEdge(int a, int b, int cap){
        g[a].pb(e.size());
        e.pb({b, 0, cap});
        g[b].pb(e.size());
        e.pb({a, 0, 0});
    }

    int minFlow, start, finish;

    bool bfs(){
        for (int i = 0; i < N; i++) dp[i] = -1;
        dp[start] = 0;
        vector<int> st;
        int uk = 0;
        st.pb(start);
        while(uk < st.size()){
            int v = st[uk++];
            for (int to : g[v]){
                auto ed = e[to];
                if (ed.cap - ed.flow >= minFlow && dp[ed.to] == -1){
                    dp[ed.to] = dp[v] + 1;
                    st.pb(ed.to);
                }
            }
        }
        return dp[finish] != -1;
    }
    
    int dfs(int v, int flow){
        if (v == finish) return flow;
        for (; ptr[v] < g[v].size(); ptr[v]++){
            int to = g[v][ptr[v]];
            edge ed = e[to];
            if (ed.cap - ed.flow >= minFlow && dp[ed.to] == dp[v] + 1){
                int add = dfs(ed.to, min(flow, ed.cap - ed.flow));
                if (add){
                    e[to].flow += add;
                    e[to ^ 1].flow -= add;
                    return add;
                }
            }
        }
        return 0;
    }
    
    int dinic(int start, int finish){
        Dinic::start = start;
        Dinic::finish = finish;
        int flow = 0;
        for (minFlow = (1 << 30); minFlow; minFlow >>= 1){
            while(bfs()){
                for (int i = 0; i < N; i++) ptr[i] = 0;
                while(int now = dfs(start, (int)2e9 + 7)) flow += now;
            }
        }
        return flow;
    }
} dinic;




pair<int, int> aa[5555];

bool can(int val){
    dinic.clear();
    for (int i = 0; i < nn; i++){
        dinic.addEdge(nn + mm, i, val);
    }
    for (int i = 0; i < mm; i++){
        dinic.addEdge(nn + i, nn + mm + 1, 1);
    }
    for (int i = 0; i < mm; i++){
        dinic.addEdge(aa[i].x, nn + i, 1);
        dinic.addEdge(aa[i].y, nn + i, 1);
    }
    int ans = dinic.dinic(nn + mm, nn + mm + 1);
    return ans == mm;
}


int main(){
    //freopen("input.txt", "r", stdin);
    cin >> nn >> mm;
    for (int i = 0; i < mm; i++) cin >> aa[i].x >> aa[i].y;
    for (int i = 0; i < mm; i++) aa[i].x--, aa[i].y--;
    int vl = 0, vr = mm;
    while(vl + 1 < vr){
        int vm = (vl + vr) >> 1;
        if (can(vm))
            vr = vm;
        else
            vl = vm;
    }
    cout << vr << "\n";
    can(vr);
    for (int i = 0; i < nn; i++){
        for (int to : dinic.g[i]){
            if (dinic.e[to].flow == 1){
                cout << i + 1 << ' ' << aa[dinic.e[to].to - nn].x + aa[dinic.e[to].to - nn].y - i + 1 << "\n";
            }
        }
    }
}