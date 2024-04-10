#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> Pair;

int V[400000], Pos[400000];
vector<int> G[400000];

void Read(int &a) {
    char c;
    for(c = getchar(); !isdigit(c); c = getchar());
    for(a = 0; isdigit(c); c = getchar()) {
        a = (a << 1) + (a << 3) + c - '0';
    }
}



int main() {
    int n, m, a, b;
    Read(n); Read(m);

    for(int i = 1; i <= n; ++i) {
        Read(V[i]);
        Pos[V[i]] = i;
    }

    while(m--) {
        Read(a); Read(b);
        G[max(Pos[a], Pos[b])].push_back(min(Pos[a], Pos[b]));
    }

    int j = 1;
    long long total = 0;
    for(int i = 1; i <= n; ++i) {
        for(auto vec : G[i]) {
            j = max(j, vec + 1);
        }

        total += (i - j + 1);
    }

    cout << total;

    return 0;
}