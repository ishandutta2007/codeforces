#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#include <math.h>
#include <sstream>
#include <bitset>
#define int228 long long
#define mp make_pair
#define pb push_back
using namespace std;

vector<vector<pair<int, int> > > g;
bool govno = 0;


int main(){
    int n;
    cin >> n;
    int m;
    cin >> m;
    g.resize(n);
    for (int i = 0; i < m; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        --a;
        --b;
        g[a].push_back(mp(b, c));
        g[b].push_back(mp(a, c));
    }

    
    int cm = 0;
    vector<int> used(n, 0);
    for (int i = 0; i < n; ++i){
        if (used[i])
            continue;
        ++cm;
        queue<int> q;
        q.push(i);
        used[i] = 1;
        while (!q.empty()){
            int curr = q.front();
            q.pop();
            for (int j = 0; j < g[curr].size(); ++j)
                if (!used[g[curr][j].first])
                {
                    if (g[curr][j].second == 1)
                        used[g[curr][j].first] = used[curr];
                    else
                        used[g[curr][j].first] = (used[curr] == 1 ? 2 : 1);
                    q.push(g[curr][j].first);
                }
        }
    }
    for (int i = 0; i < n; ++i){
        for (int j  =0; j < g[i].size(); ++j){
            if (g[i][j].second == 1 && used[i] != used[g[i][j].first])
                govno = 1;
            if (g[i][j].second == 0 && used[i] == used[g[i][j].first])
                govno = 1;
        }
    }
    if (govno)
    {
        cout << 0 << endl;
        return 0;
    }
    int228 ans = 1;
    for (int i = 0; i < cm; ++i)
        ans = (ans * 2) % 1000000007;
    ans *= 500000004ll;
    ans %= 1000000007;
    cout << ans << endl;

    return 228 / 1488;   
}