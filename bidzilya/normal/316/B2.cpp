#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>
using namespace std;

#ifndef ONLINE_JUDGE
ifstream cin("input.txt");
ofstream cout("output.txt");
#else
#include <iostream>
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pii;

const int max_n = 1e3 + 100;

int n, x;
int a[max_n];
int r[max_n];
int c[max_n];
int ca[max_n];
int d[max_n];
int cl = 0;

void dfs(int v) {
    if (a[v] == 0) {
        c[v] = cl;
        ca[cl] = 1;
        ++cl;
        r[v] = 0;
    } else {
        if (r[a[v]] == -1)
            dfs(a[v]);
        c[v] = c[a[v]];
        r[v] = r[a[v]] + 1;
        ca[c[v]] = r[v] + 1;
    }
}

int main() {
    cin >> n >> x;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
        r[i] = -1;
    for (int i = 1; i <= n; ++i)
        if (r[i] == -1)
            dfs(i);
    swap(ca[c[x]], ca[cl - 1]);
    --cl;
    d[0] = 1;
    for (int i = 0; i < cl; ++i)    
        for (int j = n; j >= 0; --j)
            if (d[j] && j + ca[i] <= n)
                d[j + ca[i]] = 1;
    for (int i = 0; i <= n; ++i)
        if (d[i]) 
            cout << i + r[x] + 1 << endl;
    return 0;
}