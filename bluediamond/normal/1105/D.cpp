#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e3 + 7;
const int K = 19;

int n, m, p;
int go[K];
int v[N][N];

bool valid(int r, int c)
{
        if (1 <= r && 1 <= c && r <= n && c <= m && v[r][c] == 0)
        {
                return true;
        }
        else
        {
                return false;
        }
}

int dr[] = {-1, 0, 1, 0}, dc[] = {0, 1, 0, -1};

set <pair <int, int>> active[K];

int lib = 0, cnt[K];

int main()
{
    //    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        cin >> n >> m >> p;
        for (int i = 1; i <= p; i++)
        {
                cin >> go[i];
        }
        for (int i = 1; i <= n; i++)
        {
                string s;
                cin >> s;
                for (int j = 1; j <= m; j++)
                {
                        if (s[j - 1] == '#')
                        {
                                v[i][j] = -1;
                        }
                        else
                        {
                                if ('0' <= s[j - 1] && s[j - 1] <= '9')
                                {
                                        v[i][j] = s[j - 1] - '0';
                                        cnt[v[i][j]]++;
                                        active[v[i][j]].insert(make_pair(i, j));
                                }
                                else
                                {
                                        lib++;
                                }
                        }
                }
        }
        int turn = p;
        while (true)
        {
                bool change = false;
                for (int turn = 1; turn <= p; turn++) 
                {
                        queue <pair <pair <int, int>, int>> q;
                        for (auto &it : active[turn])
                        {
                                q.push(make_pair(it, go[turn]));
                        }
                        while (q.size() > 0)
                        {
                                int r = q.front().first.first;
                                int c = q.front().first.second;
                                int lft = q.front().second;
                                q.pop();
                                if (lft > 0)
                                {
                                        for (int k = 0; k < 4; k++)
                                        {
                                                int rn = r + dr[k];
                                                int cn = c + dc[k];
                                                if (valid(rn, cn) == true)
                                                {
                                                        change = true;
                                                        lib--;
                                                        cnt[v[r][c]]++;
                                                        v[rn][cn] = v[r][c];
                                                        q.push(make_pair(make_pair(rn, cn), lft - 1));
                                                }
                                        }
                                }
                                bool gasit = false;
                                for (int k = 0; k < 4; k++)
                                {
                                        int rn = r + dr[k];
                                        int cn = c + dc[k];
                                        if (valid(rn, cn) == true)
                                        {
                                                gasit = true;
                                                break;
                                        }
                                }
                                if (gasit == true)
                                {
                                        active[v[r][c]].insert(make_pair(r, c));
                                }
                                else
                                {
                                        active[v[r][c]].erase(make_pair(r, c));
                                }
                        }
                }
                if (change == false)
                {
                        break;
                }
        }
        for (int i = 1; i <= p; i++)
        {
                cout << cnt[i] << " ";
        }
        cout << "\n";
        return 0;
}