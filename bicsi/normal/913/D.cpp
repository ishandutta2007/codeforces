#include <bits/stdc++.h>

using namespace std;

long long s = 0;
priority_queue<pair<int, int>> Q;

void Push(int value, int idx) {
    Q.emplace(value, idx);
    s += value;
}
void Pop() {
    int val = Q.top().first; Q.pop();
    s -= val;
}

long long Get() { return s; }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, t; cin >> n >> t;
    vector<tuple<int, int, int>> V;
    for (int i = 0; i < n; ++i) {
        int a, b; cin >> a >> b;
        V.emplace_back(a, b, i);
    }
    sort(V.begin(), V.end());

    for (int take = n; take >= 0; --take) {
        while (V.size()) {
            int a, b, i; tie(a, b, i) = V.back();
            if (a != take) break;
            Push(b, i);
            V.pop_back();
        }

        while ((int)Q.size() > take)
            Pop();

        if ((int)Q.size() == take && Get() <= t) {
            cout << take << endl << take << endl;
            while (!Q.empty()) {
                auto top = Q.top();
                cout << 1 + top.second << " ";
                Q.pop();
            }
            cout << endl;
            return 0;
        }
    }
}