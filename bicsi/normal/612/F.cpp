#include <bits/stdc++.h>

using namespace std;

#define MAXN 10005

int n, s;
int V[MAXN], Parent[MAXN];
map<int, int> Map;
vector<pair<int, int>> G[MAXN];
vector<int> Pos[MAXN];

int D[MAXN];
priority_queue<pair<int, int>> Q;

int getDist(int i, int j) {
    if(j < i) swap(i, j);
    return min(j - i, i + n - j);
}

char getSemn(int i, int j) {
    int d = getDist(i, j);
    if(j == i + d || j == i + d - n) return '+';
    return '-';
}

#define In(i)  i * 2
#define Out(i) i * 2 + 1

void Dijkstra(int start) {
    for(int i=1; i<=5000; i++)
        D[i] = 1e9;
    D[start] = 0;
    Q.push({0, start});

    while(!Q.empty()) {
        auto top = Q.top();
        Q.pop();

        if(-top.first != D[top.second]) continue;

        int node = top.second;
        for(auto e : G[node]) {
            int vec = e.first, cost = e.second;
            if(D[vec] > D[node] + cost) {
                D[vec] = D[node] + cost;
                Parent[vec] = node;
                Q.push({-D[vec], vec});
            }
        }
    }
}

void afis_drum(int node) {

    if(Parent[node] == 0) {
        //Muchie s->node/2
        cout << getSemn(s, node/2) << getDist(s, node/2) << '\n';
    } else {
        afis_drum(Parent[node]);

        int p = Parent[node], q = node;
        if(p % 2 == 1 && q % 2 == 0) {
            //Muchie Out -> In
            p /= 2; q /= 2;

            cout << getSemn(p, q) << getDist(p, q) << '\n';
        } else {
            //Muchie In -> Out
            p /= 2; q /= 2;
            int d = D[node] - D[Parent[node]];

            auto &W = Pos[V[p]]; int it;
            for(it = 0; W[it] != p; it++);

            char sign; int pas;
            if(q == p + d || q == p + d - n) sign = '+', pas = +1;
            else sign = '-', pas = -1;

            if(W.size() == 1) return;

            int last = it, it2 = it + pas;
            if(it2 >= int(W.size())) it2 -= int(W.size());
            if(it2 < 0) it2 += int(W.size());

            while(it != it2) {
                cout << sign << getDist(W[last], W[it2]) << '\n';
                last = it2;

                it2 += pas;
                if(it2 >= int(W.size())) it2 -= int(W.size());
                if(it2 < 0) it2 += int(W.size());

            } while(it2 != it);
        }
    }

}

void addEdge(int s, int d, int c) {
    G[s].push_back({d, c});
}

int main() {

    #ifndef ONLINE_JUDGE
    freopen("debug.in", "r", stdin);
    #endif // ONLINE_JUDGE

    cin>>n>>s;

    for(int i=1; i<=n; i++) {
        cin>>V[i];
        Map[V[i]] = 1;
    }

    int vals = 0;
    for(auto &x : Map)
        x.second = ++vals;

    for(int i=1; i<=n; i++)
        V[i] = Map[V[i]];

    //for(int i=1; i<=n; i++) cerr << V[i] << " "; cerr << endl;
    //cerr << vals;

    for(int i=1; i<=n; i++) {
        Pos[V[i]].push_back(i);
    }


    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(V[j] != V[i] + 1) continue;

            int d = getDist(i, j);
            addEdge(Out(i), In(j), d);
        }
    }

    for(int i=1; i<=vals; i++) {
        if(Pos[i].size() == 1)
            addEdge(In(Pos[i].back()), Out(Pos[i].back()), 0);
        else {
            for(int j=1; j<Pos[i].size(); j++) {
                int pl = Pos[i][j-1], pr = Pos[i][j];
                addEdge(In(pl), Out(pr), n - (pr - pl));
                addEdge(In(pr), Out(pl), n - (pr - pl));
            }

            int pb = Pos[i][0], pe = Pos[i].back();
            addEdge(In(pb), Out(pe), pe - pb);
            addEdge(In(pe), Out(pb), pe - pb);
        }
    }

    for(int i=1; i<=n; i++) {
        if(V[i] == 1) {
            addEdge(0, In(i), getDist(s, i));
        }
    }

    Parent[0] = -1;
    Dijkstra(0);

    int mind = 1e9;
    int choose = -1;

    for(int i=1; i<=n; i++) {
        if(V[i] == vals && D[Out(i)] < mind) {
            mind = D[Out(i)];
            choose = i;
        }
    }

    cout << mind << '\n';
    afis_drum(Out(choose));

    return 0;
}