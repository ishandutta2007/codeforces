#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    if(fopen("inp", "r")) freopen("inp", "r", stdin);

    string s; cin >> s;

    int cnt = 0;
    for(int i = 1; i < s.size(); ++i) {
        cnt += (s[i] != s[i - 1]);
    }

    if(cnt % 2 == 1) {
        cout << 0 << endl;
        return 0;
    }

    vector < pair < int, char > > comps;
    for(int i = 0; i < s.size(); ++i) {
        if(i == 0 || s[i] != s[i - 1]) {
            comps.emplace_back(1, s[i]);
        }
        else {
            comps.back().first++;
        }
    }

    for(int i = 0; i < comps.size() / 2; ++i) {
        if(comps[i].second != comps[comps.size() - i - 1].second) {
            cout << 0;
            return 0;
        }
        if(comps[i].first + comps[comps.size() - i - 1].first < 3) {
            cout << 0 << endl;
            return 0;
        }
    }

    if(comps[comps.size() / 2].first < 2) {
        cout << 0 << endl;
        return 0;
    }

    cout << (comps[comps.size() / 2].first + 1);

    return 0;
}