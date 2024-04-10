#include<bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

bool chk[9][9];
pair<int, int> prv[9][9];
int vis[9][9];

pii in() {
    char tmp[5];
    cin >> tmp;
    return pii(tmp[1] - '1', tmp[0] - 'a');
}

int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};

bool valid(pii p) {
    return (0 <= p.first && p.first < 8 && 0 <= p.second && p.second < 8);
}

void print(pii p) {
    putchar('a' + p.second);
    putchar('1' + p.first);
}

pii nxt(pii p, int d) {
    return pii(p.first + dx[d], p.second + dy[d]);
}

int main() {
//    freopen("in.txt", "r", stdin);
    int k; cin >> k;
    for (int i = 0; i < k; i++) {
        auto t = in();
//        cerr << t.first << ' ' << t.second << endl;
        chk[t.first][t.second] = 1;
    }
    vector<pair<pii, pii>> V;
    for (int _ = 0; _ < k; _++) {
        int a = _ / 8, b = _ % 8;
        if (chk[a][b]) continue;
        memset(vis, 0, sizeof vis);
        vis[a][b] = 1;
        queue<pii> Q;
        Q.emplace(a, b);
        vector<pii> ROAD;
//        cerr << a << ' ' << b << endl;
        while (!Q.empty()) {
            auto t = Q.front();
//            cerr << "ok " << t.first << ' ' << t.second << endl;
            Q.pop();
            if (t > make_pair(a, b) && chk[t.first][t.second]) {
                pii cur = t;
                while (cur != make_pair(a, b)) {
                    ROAD.push_back(cur);
                    cur = prv[cur.first][cur.second];
                }
                ROAD.push_back(cur);
                pii target = make_pair(a, b);
                for (int i = ROAD.size() - 1; i >= 0; i--) {
                    int x = ROAD[i].first, y = ROAD[i].second;
                    if (chk[x][y]) {
                        chk[x][y] = 0;
                        for (int j = i; j < (int)ROAD.size() - 1; j++) {
                            V.emplace_back(ROAD[j], ROAD[j+1]);
                            if (ROAD[j+1] == target) break;
                        }
                        chk[target.first][target.second] = 1;
                        target = ROAD[i];
                    }
                }
                break;
            }
            int x = t.first, y = t.second;
            for (int i = 0; i < 8; i++) {
                auto nt = nxt(t, i);
                if (!valid(nt) || vis[nt.first][nt.second]) continue;
                prv[nt.first][nt.second] = t;
                vis[nt.first][nt.second] = 1;
                Q.push(nt);
            }
        }
    }
    cout << V.size() << endl;
    for (auto t : V) {
        print(t.first);
        cout << "-";
        print(t.second);
        cout << endl;
    }
}