// https://codeforces.com/problemset/problem/1249/B2

#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
#define MAXN 200002

int n;
int parent[MAXN];
int value[MAXN];

int find(int x) {
    if(x==parent[x]) return x;
    else return parent[x] = find(parent[x]);
}

void unite(int a, int b) {
    int c = find(a);
    int d = find(b);
    if(c!=d) {
        parent[d] = c;
        value[c] += value[d];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    int q;
    cin >> q;
while(q--) {
    cin >> n;
    forn(i, n) {
        value[i] = 1;
        parent[i] = i;
    }
    int temp;
    forn(i, n) {
        cin >> temp;
        --temp;
        unite(i, temp);
    }
    forn(i, n) {
        cout << value[find(i)] << " ";
    }
    cout << endl;
}

    return 0;
}