#include<bits/stdc++.h>

using namespace std;

typedef long long li;
typedef pair<int, int> pt;

#define x first
#define y second

const int N = 200043;

li curd[N];
li sumd[N];
int used[N];

vector<pt> g[N];
map<pt, int> num;
int ans[N];

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++)
    {
        int x, y, c;
        scanf("%d %d %d", &x, &y, &c);
        --x;
        --y;
        g[x].push_back(make_pair(y, c));
        g[y].push_back(make_pair(x, c));
        sumd[x] += c;
        sumd[y] += c;
        num[make_pair(x, y)] = i;
    }
    queue<int> q;
    used[0] = 1;
    q.push(0);
    while(!q.empty())
    {
        int k = q.front();
        q.pop();
        for(auto e : g[k])
        {
            if(used[e.x]) continue;
            if(num.count(make_pair(k, e.x)))
                ans[num[make_pair(k, e.x)]] = 0;
            else
                ans[num[make_pair(e.x, k)]] = 1;
            curd[e.x] += e.y;
            if(curd[e.x] == sumd[e.x] / 2 && e.x < n - 1)
            {
                used[e.x] = 1;
                q.push(e.x);
            }
        }
    }
    for(int i = 0; i < m; i++)
        printf("%d\n", ans[i]);
}