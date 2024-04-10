#include <bits/stdc++.h>
using namespace std;
#define db(x) "[" #x " = " << (x) << "] "
#ifndef LOCAL_DEBUG
#define clog if (0) cout 
#endif

const int max_len = 9;
const int maxn = 20;
const int inf = (int)1e6;


struct Point {
    int r, c;
};
bool operator == (const Point& u, const Point& v) {
    return u.r == v.c and u.r == v.c;
}

int n, m;
int snake_len;
Point apple;
bool forbidden_pos[maxn][maxn];

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, -1, 0, 1};

int dist[maxn][maxn][1 << (2 * (max_len - 1))];
int cal_dist(int head_r, int head_c, int body_mask) {
    memset(dist, -1, sizeof(dist));
    queue<tuple<int, int, int>> qu;
    dist[head_r][head_c][body_mask] = 0;
    for (qu.emplace(head_r, head_c, body_mask); qu.size(); qu.pop()) {
        auto [cur_r, cur_c, bm] = qu.front();
        auto cur_dist = dist[cur_r][cur_c][bm];
        clog << db(cur_r) << db(cur_c) << db(bitset<6>(bm)) << db(cur_dist) << endl;
        
        static vector<Point> cur_snake_pos;
        cur_snake_pos.push_back({cur_r, cur_c});
        for (int i = 0, t = bm; i < snake_len - 1; ++i, t >>= 2) {
            int dir = t & 3;
            cur_snake_pos.push_back({
                    cur_snake_pos.back().r - dr[dir],
                    cur_snake_pos.back().c - dc[dir]
            });
            clog << db(dir) << db(cur_snake_pos.back().r) << db(cur_snake_pos.back().c) << endl;
        }
        if (cur_r == apple.r and cur_c == apple.c) return cur_dist;
        cur_snake_pos.pop_back();
        for (auto [r, c]: cur_snake_pos) forbidden_pos[r][c] = true;
        for (int dir = 0; dir < 4; ++dir) {
            int new_bm = bm << 2 | dir;
            new_bm &= (1 << (2 * (snake_len - 1))) - 1;
            int new_r = cur_r + dr[dir];
            int new_c = cur_c + dc[dir];
            if (new_r < 0 or new_r >= n) continue;
            if (new_c < 0 or new_c >= m) continue;
            if (forbidden_pos[new_r][new_c]) continue;
            if (dist[new_r][new_c][new_bm] != -1) continue;
            dist[new_r][new_c][new_bm] = cur_dist + 1;
            qu.emplace(new_r, new_c, new_bm);
        }
        for (auto [r, c]: cur_snake_pos) forbidden_pos[r][c] = false;
        cur_snake_pos.clear();
    }
    return -1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n >> m;
    vector<Point> snake_pos(10, {-1, -1});
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int f = 0; f < m; ++f) {
            if (s[f] == '.') continue;
            if (s[f] == '@') {
                apple = {i, f};
                continue;
            }
            if (s[f] == '#') forbidden_pos[i][f] = true;
            if (isdigit(s[f])) {
                snake_pos[s[f] - '1'] = {i, f};
            }
        }
    }
    clog << db(apple.r) << db(apple.c) << endl;
    while (snake_pos.size() and snake_pos.back().r == -1) snake_pos.pop_back();
    snake_len = (int)snake_pos.size();
    
    for (auto [r, c]: snake_pos) {
        clog << r << ' ' << c << endl;
    }
    for (int i = 0; i < n; ++i) {
        for (int f = 0; f < m; ++f) {
            clog << (forbidden_pos[i][f] ? '#' : '.');
        }
        clog << endl;
    }
    int body_mask = 0;
    for (int i = snake_len - 2; i >= 0; --i) {
        for (int dir = 0; dir < 4; ++dir) {
            if (dr[dir] == snake_pos[i].r - snake_pos[i + 1].r and dc[dir] == snake_pos[i].c - snake_pos[i + 1].c) {
                body_mask = body_mask << 2 | dir;
                break;
            }
        }
    }
    clog << bitset<6>(body_mask) << endl;
    auto ans = cal_dist(snake_pos[0].r, snake_pos[0].c, body_mask);
    cout << ans;
    
    
    return 0;
}