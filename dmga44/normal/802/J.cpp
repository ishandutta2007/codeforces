#include <bits/stdc++.h>
#define mx(qq, ww) (qq > ww ? qq : ww)

using namespace std;

const int SIZE = 1e2 + 1;
int n, cost[SIZE][SIZE];
vector<int> T[SIZE];

int dfs(int cur, int prev){
    int ret = 0;
    for(int i = 0;i < (int)T[cur].size();i++){
        int newn = T[cur][i];
        if(newn == prev)
            continue;
        ret = mx( ret, dfs(newn, cur) + cost[cur][newn] );
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1;i < n;i++){
        int a, b, c;
        cin >> a >> b >> c;
        cost[a][b] = cost[b][a] = c;
        T[a].push_back(b);
        T[b].push_back(a);
    }
    cout << dfs(0, -1);
    return 0;
}