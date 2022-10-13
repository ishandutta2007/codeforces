#include <bits/stdc++.h>

using namespace std;
typedef int var;

typedef pair<var, var> Pair;
typedef pair<Pair, var> Node;

auto greatF = [](Pair a, Pair b) {
    return 1LL * a.first * b.second >
           1LL * a.second * b.first;
};
auto cmp = [](Node a, Node b) {
    return greatF(a.first, b.first);
};
auto equals = [](Pair a, Pair b) {
    return a.first * b.second == a.second * b.first;
};

priority_queue<Node, vector<Node>, decltype(cmp)> Q(cmp);

#define MAXN 300000
bool Done[MAXN], Bad[MAXN];
vector<var> G[MAXN];
var n, m, k;

Pair getCoef(var node) {
    var a=0, b=0;
    for(auto vec : G[node]) {
        a++;
        b+=Done[vec];
    }
    return {a-b, a};
}

void PopTop() {
    var node = Q.top().second;
    Done[node] = 1;

    for(auto vec : G[node])
        if(!Done[vec])
            Q.emplace(getCoef(vec), vec);

    while(!Q.empty() && Done[Q.top().second])  Q.pop();
}

void Init() {
    for(var i=1; i<=n; i++)
        if(!Bad[i])
            Q.emplace(getCoef(i), i);
}

void Read() {
    cin>>n>>m>>k;
    var a, b;

    while(k--) {
        cin>>a;
        Bad[a] = Done[a] = 1;
    }

    while(m--) {
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("debug.in", "r", stdin);
    freopen("debug.out", "w", stdout);
    #endif // ONLINE_JUDGE

    Read();
    Pair good(0, 1);

    Init();
    while(!Q.empty()) {
        auto top = Q.top();
        if(greatF(top.first, good))
            good = top.first;
        PopTop();
    }

    for(var i=1; i<=n; i++) Done[i] = Bad[i];
    Init();
    while(!Q.empty()) {
        auto top = Q.top();
        if(equals(top.first, good))
            break;
        PopTop();
    }

    vector<var> Sol;
    for(var i=1; i<=n; i++)
        if(!Done[i])
            Sol.push_back(i);


    cout<<Sol.size()<<'\n';
    for(auto sol : Sol)
        cout<<sol<<' ';

    return 0;
}