#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pii pair<int, int>

const int N = 350;

int n, ans; bool vis[N][N];
int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n; vector<pair<pii, int>> cur({{{155, 155}, 2}});
    for(int i = 0; i<n; ++i){
        int t; cin >> t; vector<pair<pii, int>> tmp;
        for(auto p : cur){
            int x = p.f.f, y = p.f.s, d = p.s;
            for(int j = 1; j<=t; ++j)
                vis[x+j*dx[d]][y+j*dy[d]] = 1;
            tmp.push_back({{x+t*dx[d], y+t*dy[d]}, (d+1)&7});
            tmp.push_back({{x+t*dx[d], y+t*dy[d]}, (d+7)&7});
        }
        sort(tmp.begin(), tmp.end());
        tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
        swap(cur, tmp);
    }
    for(int i = 0; i<N; ++i)
        for(int j = 0; j<N; ++j)
            ans += vis[i][j];
    cout << ans << '\n';
}