#include <bits/stdc++.h>

using namespace std;
typedef int var;

#define MAXN 100005

var Next[MAXN];
var S[MAXN], E[MAXN];
bool Color[MAXN], Viz[MAXN];
vector<var> G[MAXN];

void dfs(var node) {
    Viz[node] = 1;
    for(auto vec : G[node]) {
        if(Viz[vec]) continue;

        Color[vec] = Color[node] ^ 1;
        dfs(vec);
    }
}

auto cmp = [](var a, var b) {return S[a] > S[b];};
priority_queue<var, vector<var>, decltype(cmp)> Heap(cmp);

int main() {
    #ifndef ONLINE_JUDGE
    freopen("debug.in", "r", stdin);
    #endif // ONLINE_JUDGE

    var n, l, r;
    cin>>n;
    Next[0] = 1;
    for(var i=1; i<=n; i++) {
        cin>>S[i]>>E[i];
        Heap.push(i);
    }

    while(Heap.size() >= 2) {
        int i = Heap.top(); Heap.pop();
        int j = Heap.top(); Heap.pop();

        if(E[i] < S[j]) Heap.push(j);
        else {
            G[i].push_back(j);
            G[j].push_back(i);

            if(E[i] < E[j]) {
                S[j] = E[i] + 1;
                Heap.push(j);
            } else if(E[i] > E[j]) {
                S[i] = E[j] + 1;
                Heap.push(i);
            }
        }
    }

    for(int i=1; i<=n; i++) {
        if(!Viz[i])
            dfs(i);
    }

    for(int i=1; i<=n; i++) {
        cout<<Color[i]<<" ";
    }

    return 0;
}