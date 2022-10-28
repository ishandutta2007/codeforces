#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cstdlib>
#include<string>
#include<bitset>
#include<iomanip>
#include<deque>
#include<utility>
#include<functional>
#include<sstream>
#include<ctime>
#define INF 1000000000
#define fi first
#define se second
#define N 100005
#define P 1000000007
#define debug(x) cerr<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
int a[N], b[N];
priority_queue<int, vector<int>, greater<int> > q;
vector<int> p[N], vt[N];
int main()
{
    int n, i, j, now, ans, sum = 0, cnt, res = 0, st;
    set<int> cd;
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        scanf("%d%d", &a[i], &b[i]);
        p[a[i]].push_back(b[i]);
    }
    st = now = max(1, (int)p[0].size());
    if (p[0].size() == 0)
        res = -1;
    for (i = 1; i <= 100000; i++)
    {
        if (p[i].empty())
            continue;
        sort(p[i].begin(), p[i].end());
        if (p[i].size() >= now)
        {
            cd.insert(i);
            for (j = 0; j < p[i].size() - now + 1; j++)
            {
                res++;
                sum += p[i][j];
                vt[i].push_back(p[i][j]);
            }
            for (; j < p[i].size(); j++)
                q.push(p[i][j]);
        }
        else
        {
            for (j = 0; j < p[i].size(); j++)
                q.push(p[i][j]);
        }
    }
    ans = sum;
    //debug(sum);
    for (now++; now <= n; now++)
    {
        vector<int> del;
        res--;
        for (auto x : cd)
        {
            int len = vt[x].size(), y;
            //debug(len - (now - st));
            y = vt[x][len - (now - st)];
            sum -= y;
            q.push(y);
            res--;
            if (len - (now - st) == 0)
                del.push_back(x);
        }
        //debug(res);
        while (res < 0)
        {
            sum += q.top();
            q.pop();
            res++;
        }
        //debug(sum);
        for (auto x : del)
            cd.erase(x);
        ans = min(ans, sum);
    }
    cout << ans << endl;
    return 0;
}
// davidlee1999WTK 2017/
// ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000") compiler c++,not g++
//#include<bits/stdc++.h>
/*

*/