#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> pos;
const int dr[] = {-2, -1, +1, +2, -2, -1, +1, +2};
const int dc[] = {-1, -2, -2, -1, +1, +2, +2, +1};
int G[20][20], vis[20][20];
pos fa[20][20];
char tmp[1000];
vector<pos> BFS(pos s, pos t){
    queue<pos> Q;
    Q.push(s);
    vis[s.first][s.second] = true;
    memset(vis, 0, sizeof(vis));
    memset(fa, 0, sizeof(fa));
    while (!Q.empty()){
        pos u = Q.front(); Q.pop();
        for (int i = 0; i < 8; ++i){
            pos v = pos(u.first + dr[i], u.second + dc[i]);
            if (v.first > 0 && v.second > 0 && v.first <= 8 && v.second <= 8 && !vis[v.first][v.second]){
                vis[v.first][v.second] = true;
                fa[v.first][v.second] = u;
                if (v == t) goto end;
                Q.push(v);
            }
        }
    }
    end:;
    vector<pos> ans;
    while (t != s){
        ans.push_back(t);
        t = fa[t.first][t.second];
    }
    ans.push_back(s);
    return ans;
}
int main()
{
   // freopen("in", "r", stdin);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i){
        scanf(" %s", tmp);
        int c = tmp[0] - 'a' + 1, r = tmp[1] - '0';
        G[r][c] = true;
    }
    vector<string> ans;
    int r = 1, c = 1, x, y;
    for (int tot = 0; tot  < n; ){
        while (G[r][c]){
            ++tot;
            c += 1;
            if (c == 9) r += 1, c = 1;
        }
        if (tot >= n) break;
        for (int i = 8; i >= 1; --i)
            for (int j = 8; j >= 1; --j)
                if (G[i][j]){x = i, y = j; goto finish;}
        finish:;
        vector<pos> seq = BFS(pos(x, y), pos(r, c));
        //reverse(seq.begin(), seq.end());
        int last = 1;
        for (int i = 1; i < seq.size(); ++i){
            pos u = seq[i], v = seq[i - 1];
            if (G[u.first][u.second]){
                for (int j = i; j >= last; --j){
                    pos u = seq[j - 1], v = seq[j];
                    sprintf(tmp, "%c%d-%c%d", (char)('a' + v.second - 1), v.first,  (char)('a' + u.second - 1), u.first);
                    ans.push_back(tmp);
                }
                last = i + 1;
            }
        }
        G[x][y] = false;
        G[r][c]=true;
    }
    printf("%d\n", ans.size());
    for (auto res : ans)
        puts(res.c_str());
}