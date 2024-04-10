#include <bits/stdc++.h>
using namespace std;

const int odine6 = (int)1e6+5;

int l[odine6], r[odine6];
bool val[odine6];
string op[odine6];

bool res;

bool reversed[odine6];

bool calc(int u) {
    if (op[u] == "IN")
        return val[u] = l[u];
    if (op[u] == "NOT")
        return val[u] = !calc(l[u]);
    if (op[u] == "AND")
        return val[u] = calc(l[u])&calc(r[u]);
    if (op[u] == "OR")
        return val[u] = calc(l[u])|calc(r[u]);
    if (op[u] == "XOR")
        return val[u] = calc(l[u])^calc(r[u]);
    
    return true;    //compiler cap
}

void dfs(int u) {
    if (op[u] == "IN") {
        reversed[u] = true;
        return;
    }
    
    if (op[u] == "NOT") {
        dfs(l[u]);
        return;
    }
    if (op[u] == "AND") {
        if (val[l[u]] == true)
            dfs(r[u]);
        if (val[r[u]] == true)
            dfs(l[u]);
    }
    if (op[u] == "OR") {
        if (val[l[u]] == false)
            dfs(r[u]);
        if (val[r[u]] == false)
            dfs(l[u]);
    }
    if (op[u] == "XOR") {
        dfs(l[u]);
        dfs(r[u]);
    }
        
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++) {
        cin>>op[i];
        cin>>l[i];
        if (op[i]!="NOT" && op[i]!="IN")
            cin>>r[i];
    }
    res = calc(1);
    dfs(1);
    for (int i=1; i<=n; i++) {
        if (op[i] == "IN") {
            if (reversed[i])
                cout << !res;
            else
                cout << res;
        }
    }
}