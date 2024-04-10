#include<bits/stdc++.h>

using namespace std;

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

typedef pair<int, int> pt;

int main()
{
    string s, t;
    cin >> s >> t;
    vector<vector<vector<pt>>> g(8, vector<vector<pt>>(8));
    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++)
            for(int k = 0; k < 8; k++)
            {
                int x = i + dx[k], y = j + dy[k];
                if(x >= 0 && x < 8 && y >= 0 && y < 8)
                    g[i][j].push_back({x, y});   
            }

    vector<vector<int>> d(8, vector<int>(8, int(1e9)));
    int sx = s[0] - 'a';
    int sy = s[1] - '1';
    int tx = t[0] - 'a';
    int ty = t[1] - '1';
    d[sx][sy] = 0;
    vector<vector<pt>> p(8, vector<pt>(8, {-1, -1}));
    queue<pt> q;
    q.push({sx, sy});
    while(!q.empty())
    {
        pt k = q.front();
        q.pop();
        for(auto v : g[k.first][k.second])
        {
            if(d[v.first][v.second] > d[k.first][k.second] + 1)
            {
                d[v.first][v.second] = d[k.first][k.second] + 1;
                q.push(v);
                p[v.first][v.second] = k;
            }
        }
    }

    cout << d[tx][ty] << endl;
    int cx = tx, cy = ty;
    vector<pt> path;
    while(cx != sx || cy != sy)
    {
        path.push_back({cx, cy});
        pair<int, int> c = p[cx][cy];
        cx = c.first;
        cy = c.second;
    }
    path.push_back({sx, sy});
    reverse(path.begin(), path.end());
    for(int i = 0; i + 1 < path.size(); i++)
    {
        string cur = "";
        if(path[i].first < path[i + 1].first)
            cur += "R";
        if(path[i].first > path[i + 1].first)
            cur += "L";

        if(path[i].second < path[i + 1].second)
            cur += "U";
        if(path[i].second > path[i + 1].second)
            cur += "D";
        cout << cur << endl;
    }
}