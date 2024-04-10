#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    string word = "Bulbasaur";
    string s;
    cin >> s;
    map <char, int> have, need;

    for (auto &ch : word) {
        need[ch]++;
    }

    for (auto &ch : s) {
        have[ch]++;
    }

    int sol = (1 << 30);

    for (auto &it : need) {
        char ch = it.first;
        int cnt = it.second;
        sol = min(sol, have[ch] / cnt);
    }
    cout << sol << "\n";

    return 0;
}