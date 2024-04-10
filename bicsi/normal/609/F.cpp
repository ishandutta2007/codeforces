#include <bits/stdc++.h>

using namespace std;

int n, m;
multiset<pair<int, int>> Wait;

int AIB[500000], X[500000], L[500000], I[500000], Sol[500000];

void add(int pos, int val) {
    for(int i=pos; i<=n; i += (i & -i))
        AIB[i] = max(AIB[i], val);
}

int query(int k) {
    int sol = 0, i, now = 0;
    for(i=1; i<=n; i<<=1);
    for(i>>=1; i; i>>=1) {
        if(sol+i <= n && max(now, AIB[sol+i]) < k) {
            now = max(now, AIB[sol+i]);
            sol += i;
        }
    }

    return sol + 1;
}

int dump(int i) {
    int r = 0;
    for(;i;i-=(i&-i))
        r = max(r, AIB[i]);
    return r;
}

int main() {

    #ifndef ONLINE_JUDGE
    freopen("debug.in", "r", stdin);
    #endif

    cin>>n>>m;

    for(int i=1; i<=n; i++) {
        cin>>X[i]>> L[i];
        I[i] = i;
    }

    sort(I+1, I+n+1, [](int a, int b) {return X[a] < X[b];});

    for(int i=1; i<=n; i++) {
        add(i, X[I[i]] + L[I[i]]);
    }


    int p, b;
    for(int i=1; i<=m; i++) {
        cin>>p>>b;

        int pos = query(p);

        Wait.insert({p, b});
        if(pos <= n) {
            int ind = I[pos];
            while(true) {
                auto it = Wait.lower_bound({X[ind], 0});
                if(it == Wait.end() || it->first > X[ind] + L[ind]) break;

                L[ind] += it->second;
                Sol[ind] ++;
                Wait.erase(it);
            }

            add(pos, X[ind] + L[ind]);
        }
    }

    for(int i=1; i<=n; i++) {
        cout << Sol[i] << ' ' << L[i] << '\n';
    }

    return 0;
}