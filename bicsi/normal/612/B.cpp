#include <bits/stdc++.h>

using namespace std;

#define MAXN 300000

int Pos[MAXN];

int main() {

    int n, fragm;
    cin>>n;

    for(int i=1; i<=n; i++) {
        cin>>fragm;
        Pos[fragm] = i;
    }

    int64_t total = 0;
    for(int i=2; i<=n; i++) {
        total += max(Pos[i-1] - Pos[i], Pos[i] - Pos[i-1]);
    }

    cout << total;


    return 0;
}