#include <bits/stdc++.h>
using namespace std;

inline int GetBit(int mask, int num)
{
    return (mask >> num) & 1;
}

inline int GetAmountOfBits(int mask)
{
    int ans = 0;
    while (mask > 0) {
        ans += (mask & 1);
        mask >>= 1;
    }
    return ans;
}

const int kAlphabetSize = 26;

const int kDx[4] = {-1, 0, 0, 1};
const int kDy[4] = {0, -1, 1, 0};

int n, m, k;
vector<vector<char> > field;
int si, sj;
int fi, fj;

bool ans_found;
int ans_len;
string ans_path;

vector<vector<bool> > used;
vector<vector<bool> > inused;
vector<vector<int> > dist;

vector<int> char_posses_i[kAlphabetSize];
vector<int> char_posses_j[kAlphabetSize];

void ClearUsed(int mask, vector<vector<bool> >& used)
{
    for (int c = 0; c < kAlphabetSize; ++c) {
        if (!GetBit(mask, c)) {
            continue;
        }
        for (int i = 0; i < (int) char_posses_i[c].size(); ++i) {
            used[char_posses_i[c][i]][char_posses_j[c][i]] = false;
        }
    }
    used[si][sj] = false;
    used[fi][fj] = false;
}

void UpdateAns(int mask)
{
    if (dist[fi][fj] == 1) {
        ans_found = true;
        ans_len = 1;
        ans_path = "";
        return;
    }
    string cur_path;
    cur_path.reserve(dist[fi][fj] - 1);
    deque<int> qi;
    deque<int> qj;
    
    qi.push_back(fi);
    qj.push_back(fj);
    inused[fi][fj] = true;
    while (!qi.empty()) {
        int ci = qi.front();
        qi.pop_front();
        int cj = qj.front();
        qj.pop_front();
        
        for (int step_index = 0; step_index < 4; ++step_index) {
            int ni = ci + kDx[step_index];
            int nj = cj + kDy[step_index];
            
            if (ni >= 0 && ni < n && nj >= 0 && nj < m && 
                    !inused[ni][nj] && used[ni][nj] && dist[ni][nj] + 1 == dist[ci][cj]) {
                inused[ni][nj] = true;
                qi.push_back(ni);
                qj.push_back(nj);
            }
        }
    }
    
    qi.push_back(si);
    qj.push_back(sj);
    used[si][sj] = false;
    while (!qi.empty()) {
        char min_char = field[qi[0]][qj[0]];
        for (int i = 1; i < (int) qi.size(); ++i) {
            min_char = min(min_char, field[qi[i]][qj[i]]);
        }
        
        if (min_char != 'S' && min_char != 'T') {
            cur_path.push_back(min_char);
        }
        
        int sz = qi.size();
        for (int itr = 0; itr < (int) sz; ++itr) {
            int ci = qi.front();
            qi.pop_front();
            int cj = qj.front();
            qj.pop_front();
            
            if (field[ci][cj] != min_char) {
                continue;
            }
            
            for (int step_index = 0; step_index < 4; ++step_index) {
                int ni = ci + kDx[step_index];
                int nj = cj + kDy[step_index];
                
                if (ni >= 0 && ni < n && nj >= 0 && nj < m && 
                        inused[ni][nj] && 
                        used[ni][nj] && 
                        dist[ni][nj] == dist[ci][cj] + 1) {
                    used[ni][nj] = false;
                    qi.push_back(ni);
                    qj.push_back(nj);
                }
            }
        }
    }
    
    ClearUsed(mask, inused);
    
    if (!ans_found || dist[fi][fj] < ans_len || cur_path < ans_path) {
        ans_found = true;
        ans_len = dist[fi][fj];
        ans_path = cur_path;
    }
}

void Solve(int mask) 
{
    queue<int> qi;
    queue<int> qj;
    
    used[si][sj] = true;
    dist[si][sj] = 0;
    qi.push(si);
    qj.push(sj);
    while (!qi.empty()) {
        int ci = qi.front(); 
        qi.pop();
        int cj = qj.front();
        qj.pop();
        
        for (int step_index = 0; step_index < 4; ++step_index) {
            int ni = ci + kDx[step_index];
            int nj = cj + kDy[step_index];
            
            if (ni >= 0 && ni < n && nj >= 0 && nj < m &&
                    (field[ni][nj] == 'T' || field[ni][nj] == 'S' || GetBit(mask, field[ni][nj] - 'a')) && 
                    !used[ni][nj]) {
                used[ni][nj] = true;
                dist[ni][nj] = dist[ci][cj] + 1;
                qi.push(ni);
                qj.push(nj);
            }
        }
    }
    
    if (used[fi][fj]) {
        if (!ans_found || dist[fi][fj] <= ans_len) {
            UpdateAns(mask);
        }
    }
    
    ClearUsed(mask, used);
}

void Dfs(int c, int mask, int num)
{
    if (c == kAlphabetSize) {
        Solve(mask);
        return;
    }
    if (num + 1 <= k) {
        Dfs(c + 1, mask + (1 << c), num + 1);
    }
    Dfs(c + 1, mask, num);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m >> k;
    field.resize(n, vector<char>(m));
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> field[i][j];
            if (field[i][j] == 'S') {
                si = i;
                sj = j;
            } 
            if (field[i][j] == 'T') {
                fi = i;
                fj = j;
            }
        }
    }
    
    used.assign(n, vector<bool>(m, false));
    inused.assign(n, vector<bool>(m, false));
    dist.resize(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (field[i][j] >= 'a' && field[i][j] <= 'z') {
                char_posses_i[field[i][j] - 'a'].push_back(i);
                char_posses_j[field[i][j] - 'a'].push_back(j);
            }
        }
    }
    
    ans_found = false;
    Dfs(0, 0, 0);
    
    if (!ans_found) {
        cout << -1 << endl;
    } else {
        cout << ans_path << endl;
    }
    
    return 0;
}