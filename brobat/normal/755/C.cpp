// https://codeforces.com/problemset/problem/755/C

#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
#define MAXN 10000

int n;
int parent[MAXN];

int find(int x) {
    if(x==parent[x]) return x;
    else return parent[x] = find(parent[x]);
}

void unite(int a,int b) {
    int c = find(a);
    int d = find(b);
    if(c!=d) {
        parent[d] = c;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    cin >> n;
    forn(i, n) parent[i] = i;
    int temp;
    forn(i, n) {
        cin >> temp;
        --temp;
        unite(i, temp);
    }
    temp = 0;
    forn(i, n) {
        if(i==parent[i]) {
            temp += 1;
        }
    }
    cout << temp;
    return 0;
}