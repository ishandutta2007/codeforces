// https://codeforces.com/problemset/problem/1057/A

#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
#define MAXN 200000

int n;
int parent[MAXN];
deque <int> q;

int find(int x) {
    if(x==0) {
        return 0; 
    } else {
        q.push_front(parent[x]);
        return find(parent[x]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    cin >> n;
    parent[0] = 0;
    forn(i, n) {
        if(i==0) continue;
        cin >> parent[i];
        --parent[i];
    }
    q.push_front(n-1);
    find(n-1);
    while(!q.empty()) {
        cout << (q.front()+1) << " ";
        q.pop_front();
    }
    return 0;
}