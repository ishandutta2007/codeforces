#include <bits/stdc++.h>
using namespace std;

const int kDx[4] = {-1, 0, 0, 1};
const int kDy[4] = {0, -1, 1, 0};

const char kRat = 'R';
const char kWall = 'X';

const int kMaxD = 8;
const int kMaxAmountOfRats = 300;

int n, m, d;
vector<vector<char> > a;
vector<vector<int> > used;

vector<pair<int, int> > GetUsed(int si, int sj)
{
    vector<pair<int, int> > res;
    queue<int> qi, qj;
    qi.push(si);
    qj.push(sj);
    used[si][sj] = 0;
    res.push_back(make_pair(si, sj));
    while (!qi.empty()) {
        int ci = qi.front();
        int cj = qj.front();
        qi.pop();
        qj.pop();

        if (used[ci][cj] == d) {
            continue;
        }

        for (int t = 0; t < 4; ++t) {
            int ni = ci + kDx[t];
            int nj = cj + kDy[t];

            if (ni >= 0 && ni < n && nj >= 0 && nj < m && used[ni][nj] == -1 && a[ni][nj] != kWall) {
                used[ni][nj] = used[ci][cj] + 1;
                res.push_back(make_pair(ni, nj));
                qi.push(ni);
                qj.push(nj);
            }
        }
    }
    for (int i = 0; i < (int) res.size(); ++i) {
        used[res[i].first][res[i].second] = -1;
    }
    return res;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> d;

    a.resize(n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    used.assign(n, vector<int>(m, -1));

    vector<pair<int, int> > rats;

    vector<vector<int> > rat_index(n, vector<int>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == kRat) {
                rats.push_back(make_pair(i, j));
                if (rats.size() > kMaxAmountOfRats) {
                    cout << -1 << endl;
                    return 0;
                }
                rat_index[i][j] = rats.size() - 1;
            }
        }
    }

    vector<vector<pair<int, int> > > rat_a_used(rats.size());
    for (int i = 0; i < (int) rats.size(); ++i) {
        rat_a_used[i] = GetUsed(rats[i].first, rats[i].second);
    }

    /*
    for (int i = 0; i < (int) rats.size(); ++i) {
        cout << i << ": " << endl;
        for (int j = 0; j < (int) rat_a_used[i].size(); ++j) {
            cout << "  " << rat_a_used[i][j].first << " " << rat_a_used[i][j].second << endl;
        }
    }
    */

    vector<vector<int> > amount_of_rat_used(n, vector<int>(m, 0));
    for (int i = 0; i < (int) rats.size(); ++i) {
        for (int j = 0; j < (int) rat_a_used[i].size(); ++j) {
            int ci = rat_a_used[i][j].first;
            int cj = rat_a_used[i][j].second;
            ++amount_of_rat_used[ci][cj];
        }
    }

    /*
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << amount_of_rat_used[i][j] << " ";
        }
        cout << endl;
    }
    */

    vector<pair<int, int> > first_bomb_pos = rat_a_used[0];

    for (int index = 0; index < (int) first_bomb_pos.size(); ++index) {
        int fi = first_bomb_pos[index].first;
        int fj = first_bomb_pos[index].second;

        vector<pair<int, int> > first_used = GetUsed(fi, fj);

        for (int i = 0; i < (int) first_used.size(); ++i) {
            int ci = first_used[i].first;
            int cj = first_used[i].second;

            if (a[ci][cj] == kRat) {
                int ri = rat_index[ci][cj];

                for (int t = 0; t < (int) rat_a_used[ri].size(); ++t) {
                    int ti = rat_a_used[ri][t].first;
                    int tj = rat_a_used[ri][t].second;

                    --amount_of_rat_used[ti][tj];
                }
            }
        }

        vector<int> rat_rem(rats.size(), 0);
        for (int i = 0; i < (int) first_used.size(); ++i) {
            int ci = first_used[i].first;
            int cj = first_used[i].second;

            if (a[ci][cj] == kRat) {
                int ri = rat_index[ci][cj];

                rat_rem[ri] = 1;
            }
        }

        int second_rat = -1;
        for (int i = 0; i < (int) rats.size(); ++i) {
            if (rat_rem[i] == 0) {
                second_rat = i;
                break;
            }
        }

        if (second_rat == -1) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (a[i][j] != kWall && !(i == fi && j == fj)) {
                        cout << fi + 1 << " " << fj + 1 << " " << i + 1 << " " << j + 1 << endl;
                        return 0;
                    }
                }
            }
        }

        int amount_of_rat_rem = 0;
        for (int i = 0; i < (int) rats.size(); ++i) {
            if (rat_rem[i] == 0) {
                ++amount_of_rat_rem;
            }
        }

        for (int i = 0; i < (int) rat_a_used[second_rat].size(); ++i) {
            int ti = rat_a_used[second_rat][i].first;
            int tj = rat_a_used[second_rat][i].second;

            if (ti == fi && tj == fj) {
                continue;
            }

            if (amount_of_rat_used[ti][tj] == amount_of_rat_rem) {
                cout << fi + 1 << " " << fj + 1 << " " << ti + 1 << " " << tj + 1 << endl;
                return 0;
            }
        }

        for (int i = 0; i < (int) first_used.size(); ++i) {
            int ci = first_used[i].first;
            int cj = first_used[i].second;

            if (a[ci][cj] == kRat) {
                int ri = rat_index[ci][cj];

                for (int t = 0; t < (int) rat_a_used[ri].size(); ++t) {
                    int ti = rat_a_used[ri][t].first;
                    int tj = rat_a_used[ri][t].second;

                    ++amount_of_rat_used[ti][tj];
                }
            }
        }
    }

    cout << -1 << endl;

    return 0;
}