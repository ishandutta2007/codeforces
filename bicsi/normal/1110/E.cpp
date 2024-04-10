#include <bits/stdc++.h>

using namespace std;

vector<int> Read(int n) {
    vector<int> v;
    int last = -1;
    int fst = -1;
    for (int i = 0; i < n; ++i) {
        int now; cin >> now;
        if (i > 0) v.push_back(now - last);
        else fst = now;
        last = now;
    }
    sort(v.begin(), v.end());
    v.push_back(fst);
    v.push_back(last);
    return v;
}

int main() {
    int n; cin >> n;
    cout << (Read(n) == Read(n) ? "Yes\n" : "No\n");
    return 0;
}