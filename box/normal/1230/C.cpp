#include <iostream>
#include <cstring>
#include <utility>
#include <vector>
using namespace std;

bool H[7][7];
bool tmp[7][7];

void init() {
    memset(H, 0, sizeof H);
    for(int i=1; i<=6; i++)
        for(int j=i; j<=6; j++) {
            H[i][j] = 1;
            H[j][i] = 1;
        }
}

int no[10];
vector<pair<int, int>> elist;
int n;

int dfs(int node) {
    if(node == n+1) {
        memcpy(tmp, H, sizeof tmp);
        int ans = 0;
        for(auto& p:elist) {
            //cout << p.first << ' ' << p.second << ' ' << no[p.first] << ' ' << no[p.second] << ' ' << tmp[no[p.first]][no[p.second]] << endl;
            if(tmp[no[p.first]][no[p.second]]) {
                ans++;
                tmp[no[p.first]][no[p.second]] = 0;
                tmp[no[p.second]][no[p.first]] = 0;
            }
        }
        return ans;
    }
    int ans = 0;
    for(int ex=1;ex<=6;ex++) {
        no[node]=ex;
        ans = max(ans,dfs(node+1));
    }
    return ans;
}

int main() {
    init();
    int m; cin >> n >> m;
    for(int i=0; i<m; i++) {
        int v, e; cin >> v >> e;
        elist.push_back(make_pair(v, e));
    }
    cout << dfs(1) << endl;
}