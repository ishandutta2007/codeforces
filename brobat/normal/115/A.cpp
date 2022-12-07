// https://codeforces.com/problemset/problem/115/A

#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
#define MAXN 2000

int n;
int temp, ans;
int parent[MAXN];

int find(int x) {
    if(x==parent[x]) {
        temp++;
        return x;
    }
    else {
        temp++;
        return find(parent[x]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    ans = 0;
    cin >> n;
    forn(i, n) {
        cin >> parent[i];
        --parent[i];
        if(parent[i]==-2) parent[i] = i;
    }
    forn(i, n) {
        temp = 0;
        find(i);
        if(temp > ans) ans = temp;
    }
    cout << ans;
    return 0;
}