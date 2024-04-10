#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> Pair;

vector<Pair> V;
int AIB[1000000], B[500000], E[500000], Sol[500000];

void add(int pos) {
    for(;pos;pos-=(pos&-pos)) {
        AIB[pos] += 1;
    }
}

int query(int pos) {
    int s = 0;
    for(;pos<=5e5;pos+=(pos&-pos))
        s += AIB[pos];
    return s;
}

int main() {
    int n, m, a, b;
    cin >> n;

    for(int i = 1; i <= n; ++i) {
        cin >> B[i] >> E[i];
        V.push_back({B[i], 2*i});
        V.push_back({E[i], 2*i+1});
    }

    sort(V.begin(), V.end());
    for(int i = 0 ; i < V.size(); ++i) {
        int solve = V[i].second / 2;
        int e = V[i].second % 2;

        if(e) {
            Sol[solve] = query(B[solve] + 1);
            add(B[solve]);
        } else {
            B[solve] = i + 1;
        }
    }

    for(int i = 1; i <= n; ++i) {
        cout << Sol[i] << '\n';
    }

    return 0;
}