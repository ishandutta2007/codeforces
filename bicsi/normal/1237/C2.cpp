#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    map<int, map<int, map<int, int>>> mp3;
    for (int i = 0; i < n; ++i) {
        int x, y, z; cin >> x >> y >> z;
        mp3[x][y][z] = i + 1;
    }
    auto dome = [&](vector<int>& ret) {
        for (int i = 0; i + 1 < (int)ret.size(); i += 2) {
            cout << ret[i] << " " << ret[i + 1] << '\n';
        }
        if (ret.size() % 2) return ret.back();
        return -1;
    };
    
    auto solve1 = [&](map<int, int>& mp1) {
        vector<int> ret;
        for (auto& p : mp1) {
            ret.push_back(p.second);
        }
        return dome(ret);
    };
    auto solve2 = [&](map<int, map<int, int>>& mp2) {
        vector<int> ret;
        for (auto& p : mp2) {
            int now = solve1(p.second);
            if (now != -1) ret.push_back(now);
        }
        return dome(ret);
    };

    vector<int> ret;
    for (auto p : mp3) {
        int now = solve2(p.second);
        if (now != -1) ret.push_back(now);
    }
    assert(dome(ret) == -1);
    return 0;
}