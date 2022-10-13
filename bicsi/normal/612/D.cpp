#include <bits/stdc++.h>

using namespace std;

#define MAXN 300000

unordered_map<int, int> Add, Rem;
vector<int> V;
vector<pair<int, int>> Segms;

void Read(int &x) {
    char c, sgn = 0;
    for(c = getchar(); !isdigit(c) && c != '-'; c = getchar());
    if(c == '-') {sgn = 1; c = getchar();}
    for(x = 0; isdigit(c); c = getchar())
        x = (x << 1) + (x << 3) + c - '0';
    if(sgn) x = -x;
}

int main() {

    #ifndef ONLINE_JUDGE
    freopen("debug.in", "r", stdin);
    #endif // ONLINE_JUDGE

    int n, k, a, b;
    Read(n); Read(k);

    for(int i=1; i<=n; i++) {
        Read(a); Read(b);
        Add[a]++;
        Rem[b]++;
        V.push_back(a);
        V.push_back(b);
    }

    sort(V.begin(), V.end());
    V.resize(unique(V.begin(), V.end()) - V.begin());

    bool insegm = 0;
    int total = 0;

    for(auto x : V) {
        total += Add[x];
        if(!insegm && total >= k) {
            Segms.push_back({x, 0});
            insegm = 1;
        }

        total -= Rem[x];
        if(insegm && total < k) {
            Segms.back().second = x;
            insegm = 0;
        }
    }

    cout << Segms.size() << '\n';
    for(auto x : Segms) {
        cout << x.first << " " << x.second << '\n';
    }

    return 0;
}