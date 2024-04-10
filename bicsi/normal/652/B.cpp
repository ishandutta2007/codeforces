#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> Pair;

int V[200000], Viz[200000];

int main() {
    int n;
    cin >> n;

    for(int i = 1; i <= n; ++i) cin >> V[i];
    sort(V + 1, V + n + 1);

    for(int i = 1; i <= n; ++i) {
        if(!Viz[i]) {cout << V[i] << " "; Viz[i] = 1;}
        if(!Viz[n - i + 1]) {cout << V[n - i + 1] << " "; Viz[n - i + 1] = 1;}
    }

    return 0;
}