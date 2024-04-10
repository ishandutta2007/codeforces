#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <set>
using namespace std;
int n;
int vis[100];
int x[100], y[100];
void bfs(int s)
{
    queue<int> Q;
    Q.push(s);
    vis[s] = 1;
    while(Q.size())
    {
        int t = Q.front();
        Q.pop();
        for(int k = 0; k < 100; k++)
        {
            if(!vis[k] && (x[k] == x[t] || y[k]==y[t]) )
            {
                vis[k] = 1;
                Q.push(k);
            }
        }
    }
}
int main()
{
    cin >> n;

    for(int k = 0; k < n; k++)
        cin >> x[k] >> y[k];
    int cnt = 0;
    for(int k = 0; k < n; k++)
    {
        if(!vis[k])
        {
            cnt++;
            bfs(k);
        }
    }
    cout << cnt - 1 << endl;
    return 0;
}