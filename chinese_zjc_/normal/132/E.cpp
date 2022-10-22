//This Code was made by Chinese_zjc_.
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <map>
#include <set>
#include <ctime>
// #define debug
#define int long long
#define double long double
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int n, m, a[255], inid[255], outid[255], endid[255], lst[255], s, t, S, T, head[5005], ncnt, ecnt, cost, from[5005];
int Cost[5005], Flow[5005];
bool in[5005];
std::map<int, int> MAP;
std::vector<std::pair<bool, std::pair<int, int>>> ans;
struct edge
{
    int n, t, cost, flow;
} e[5005];
void add_edge(int F, int T, int COST, int FLOW)
{
    e[ecnt] = {head[F], T, COST, FLOW};
    head[F] = ecnt++;
}
void add_flow(int F, int T, int COST, int FLOW)
{
    add_edge(F, T, +COST, FLOW);
    add_edge(T, F, -COST, 0);
}
int pop_count(int x)
{
    return x ? pop_count(x & (x - 1)) + 1 : 0;
}
void print()
{
    for (int i = 0; i < ncnt; ++i)
        for (int j = head[i]; ~j; j = e[j].n)
            if (j % 2 == 0)
                std::cout << i << ' ' << e[j].t << ' ' << e[j].cost << ','
                          << (e[j].flow >= INF / 2 ? "INF" : std::to_string(e[j].flow)) << std::endl;
}
bool spfa(int beg, int end)
{
    std::queue<int> que;
    std::fill(Cost, Cost + ncnt, INF);
    std::fill(Flow, Flow + ncnt, 0);
    Cost[beg] = 0;
    Flow[beg] = INF;
    que.push(beg);
    while (!que.empty())
    {
        int now = que.front();
        in[now] = false;
        que.pop();
        for (int i = head[now]; ~i; i = e[i].n)
        {
            if (e[i].flow && Cost[e[i].t] > Cost[now] + e[i].cost)
            {
                Cost[e[i].t] = Cost[now] + e[i].cost;
                Flow[e[i].t] = std::min(Flow[now], e[i].flow);
                from[e[i].t] = i;
                if (!in[e[i].t])
                {
                    in[e[i].t] = true;
                    que.push(e[i].t);
                }
            }
        }
    }
    return Cost[end] != INF;
}
int EK(int beg, int end)
{
    int res = 0;
    while (spfa(beg, end))
    {
        res += Flow[end];
        int now = end;
        while (now != beg)
        {
            e[from[now]].flow -= Flow[end];
            e[from[now] ^ 1].flow += Flow[end];
            cost += e[from[now]].cost * Flow[end];
            now = e[from[now] ^ 1].t;
        }
    }
    return res;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    memset(head, -1, sizeof(head));
    std::cin >> n >> m;
    S = ncnt++;
    T = ncnt++;
    s = ncnt++;
    t = ncnt++;
    endid[0] = ncnt++;
    for (int i = 1; i <= n; ++i)
    {
        inid[i] = ncnt++;
        outid[i] = ncnt++;
        endid[i] = ncnt++;
        std::cin >> a[i];
        lst[i] = MAP[a[i]];
        MAP[a[i]] = i;
    }
    for (int i = 1; i <= n; ++i)
    {
        add_flow(endid[i - 1], endid[i], 0, m);
        add_flow(inid[i], T, 0, 1);
        add_flow(S, outid[i], 0, 1);
        add_flow(inid[i], outid[i], 0, 1);
        add_flow(endid[i - 1], inid[i], pop_count(a[i]), 1);
        add_flow(outid[i], endid[i], 0, 1);
        if (lst[i])
            add_flow(outid[lst[i]], inid[i], 0, m);
    }
    add_flow(s, endid[0], 0, m);
    add_flow(endid[n], t, 0, m);
    add_flow(t, s, 0, m);
    EK(S, T);
    EK(s, t);
    std::vector<int> waiting;
    std::vector<int> val(m);
    for (int i = 0; i < m; ++i)
        waiting.push_back(i);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = head[endid[i - 1]]; ~j; j = e[j].n)
        {
            if (inid[i] == e[j].t && !e[j].flow)
            {
                val[waiting.back()] = a[i];
                ans.push_back({false, {waiting.back(), i}});
                waiting.pop_back();
                break;
            }
        }
        for (int j = 0; j < m; ++j)
        {
            if (val[j] == a[i])
            {
                ans.push_back({true, {j, i}});
            }
        }
        for (int j = head[outid[i]]; ~j; j = e[j].n)
        {
            if (endid[i] == e[j].t && !e[j].flow)
            {
                for (int k = 0; k < m; ++k)
                    if (val[k] == a[i])
                    {
                        val[k] = 0;
                        waiting.push_back(k);
                        break;
                    }
            }
        }
    }
    std::cout << ans.size() << ' ' << cost << std::endl;
    for (int i = 0; i < ans.size(); ++i)
    {
        if (ans[i].first)
        {
            std::cout << "print(" << char(ans[i].second.first + 'a') << ')' << std::endl;
        }
        else
        {
            std::cout << char(ans[i].second.first + 'a') << '=' << a[ans[i].second.second] << std::endl;
        }
    }
    return 0;
}