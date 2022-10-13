#include <bits/stdc++.h>

using namespace std;
typedef long long var;
typedef pair<var, var> Pair;

#define MAXN 100005
#define INF 1e15


var A[MAXN], B[MAXN], C[MAXN];

vector<Pair> G[MAXN], Gt[MAXN];
var DS[MAXN], DT[MAXN];
priority_queue< Pair, vector<Pair> >Q;
int n;

void dijk(var start, var D[], vector<Pair> GG[]) {

    for(int i=1; i<=n; i++) {
        D[i] = INF;
    }

    D[start] = 0;
    Q.push({0, start});

    while(!Q.empty()) {
        auto p = Q.top();
        Q.pop();
        var node = p.second;
        if(D[node] < -p.first) continue;

        for(auto &e : GG[node])
        if(D[e.first] > D[node] + C[e.second]) {
            D[e.first] = D[node] + C[e.second];
            Q.push({-D[e.first], e.first});
        }
    }
}

bool Good[MAXN];
bool Viz[MAXN];
var Low[MAXN], Di[MAXN], Parent[MAXN];
vector<Pair> GG[MAXN];
var tim = 0;
void dfs(var node) {
    Viz[node] = 1;
    Di[node] = ++tim;
    Low[node] = Di[node];

    for(auto &e : GG[node]) {
        if(!Viz[e.first]) {
            Parent[e.first] = e.second;
            dfs(e.first);
            Low[node] = min(Low[node], Low[e.first]);
            if(Low[e.first] == Di[e.first]) {
                Good[e.second] = 1;
            }
        } else if(e.second != Parent[node]) {
            Low[node] = min(Low[node], Low[e.first]);
        }
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("debug.in", "r", stdin);
    #endif // ONLINE_JUDGE

    var m, s, t;
    cin>>n>>m>>s>>t;

    for(int i=1; i<=m; i++) {
        cin>>A[i]>>B[i]>>C[i];
        G[A[i]].push_back({B[i], i});
        Gt[B[i]].push_back({A[i], i});
    }

    dijk(s, DS, G);
    dijk(t, DT, Gt);

    var dt = DS[t];

    for(int i=1; i<=m; i++) {
        if(DS[A[i]] + DT[B[i]] + C[i] == dt) {
            GG[A[i]].push_back({B[i], i});
            GG[B[i]].push_back({A[i], i});
        }
    }
    for(int i=1; i<=n; i++) {
        if(!Viz[i])
            dfs(i);
    }

    for(int i=1; i<=m; i++) {
        var c = DS[A[i]] + DT[B[i]] + C[i] - dt + 1;

        if(Good[i]) {cout<<"YES\n";}
        else if(c >= C[i]) {cout<<"NO\n";}
        else cout<<"CAN "<<c<<'\n';
    }


    return 0;
}