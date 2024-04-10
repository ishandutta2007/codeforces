#include <bits/stdc++.h>

using namespace std;

queue<int> Q;
long long D[500000], T[500000], Sol[500000];

int main() {

    int n, m;
    cin >> n >> m;

    long long now = 0;

    for(int i=1; i<=n; i++) {
        cin >> T[i] >> D[i];
        Sol[i] = -1;

        while(!Q.empty() && D[Q.front()] + max(now, T[Q.front()]) <= T[i]) {
            now = max(now, T[Q.front()]) + D[Q.front()];
            Sol[Q.front()] = now;
            Q.pop();
        }

        if(Q.size() <= m) {
            Q.push(i);
        }
    }

    while(!Q.empty()) {
        now = max(now, T[Q.front()]) + D[Q.front()];
        Sol[Q.front()] = now;
        Q.pop();
    }

    for(int i=1; i<=n; i++)
        cout << Sol[i] << " ";



    return 0;
}