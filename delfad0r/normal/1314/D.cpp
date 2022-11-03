#include <bits/stdc++.h>

using namespace std;

typedef long long LL;


template<typename T>
ostream& operator << (ostream& out, const vector<T>& v) {
    out << "[";
    for(const auto& x : v) {
        out << x << ", ";
    }
    return out << "]";
}

template<typename T, typename S>
ostream& operator << (ostream& out, const pair<T, S>& p) {
    return out << "{" << p.first << ", " << p.second << "}";
}

int N, K;
int G[100][100];
int shortest2[100][100][5], shortest2_v[100][100][5];

int solve(vector<int>& v) {
    if(int(v.size()) == K / 2 - 1) {
        v.push_back(0);
        auto f = [&](int x, int y) {
            for(int i = 0; i < 4; ++i) {
                if(!count(v.begin(), v.end(), shortest2_v[x][y][i])) {
                    return shortest2[x][y][i];
                }
            }
            abort();
        };
        int ans = f(0, v[0]);
        for(int i = 0; i < int(v.size()) - 1; ++i) {
            ans += f(v[i], v[i + 1]);
        }
        v.pop_back();
        return ans;
    } else {
        int ans = 1 << 30;
        for(int n = 0; n < N; ++n) {
            v.push_back(n);
            ans = min(ans, solve(v));
            v.pop_back();
        }
        return ans;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> K;
    for(int n = 0; n < N; ++n) {
        for(int m = 0; m < N; ++m) {
            cin >> G[n][m];
        }
    }
    for(int n = 0; n < N; ++n) {
        for(int m = 0; m < N; ++m) {
            vector<pair<int, int>> V;
            for(int l = 0; l < N; ++l) {
                if(l != n and l != m) {
                    V.emplace_back(G[n][l] + G[l][m], l);
                }
            }
            sort(V.begin(), V.end());
            for(int i = 0; i < 4 and i < int(V.size()); ++i) {
                shortest2[n][m][i] = V[i].first;
                shortest2_v[n][m][i] = V[i].second;
            }
        }
    }
    vector<int> v;
    cout << solve(v) << "\n";
    
    return 0;
}