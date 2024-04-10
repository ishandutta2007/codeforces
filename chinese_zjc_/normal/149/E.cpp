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
std::string s, q[105];
int m, ans;
struct SAM
{
    struct node
    {
        int pos, link, len;
        std::map<char, int> to;
    };
    std::vector<node> sam;
    int last;
    SAM()
    {
        last = 0;
        sam.push_back({0, -1, 0});
    }
    void add(char c)
    {
        int cur = sam.size();
        sam.push_back({sam[last].len + 1, 0, sam[last].len + 1});
        for (int p = last; ~p; p = sam[p].link)
        {
            std::map<char, int>::iterator q = sam[p].to.find(c);
            if (q != sam[p].to.end())
            {
                if (sam[p].len + 1 == sam[q->second].len)
                    sam[cur].link = q->second;
                else
                {
                    int add = sam.size();
                    sam.push_back({sam[q->second].pos, sam[q->second].link, sam[p].len + 1, sam[q->second].to});
                    sam[cur].link = add;
                    sam[q->second].link = add;
                    for (p = sam[p].link; ~p; p = sam[p].link)
                    {
                        std::map<char, int>::iterator tmp = sam[p].to.find(c);
                        if (tmp == sam[p].to.end() || tmp->second != q->second)
                            break;
                        tmp->second = add;
                    }
                    q->second = add;
                }
                break;
            }
            sam[p].to[c] = cur;
        }
        last = cur;
    }
} A, B;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> s >> m;
    for (int i = 0; i != (int)s.size(); ++i)
        A.add(s[i]);
    for (int i = s.size(); i--;)
        B.add(s[i]);
    // for (int i = 0; i != A.sam.size(); ++i)
    //     for (auto j : A.sam[i].to)
    //         std::cout << i << ' ' << j.second << ' ' << j.first << std::endl;
    for (int i = 1; i <= m; ++i)
    {
        std::cin >> q[i];
        if (q[i].size() == 1)
            continue;
        int p;
        int end[q[i].size() + 1];
        std::fill(end + 1, end + 1 + q[i].size(), INF);
        end[0] = 0;
        p = 0;
        for (int j = 1; j <= (int)q[i].size(); ++j)
        {
            std::map<char, int>::iterator tmp = A.sam[p].to.find(q[i][j - 1]);
            if (tmp != A.sam[p].to.end())
            {
                p = tmp->second;
                end[j] = A.sam[p].pos;
                // std::cout << end[j] << std::endl;
            }
            else
                break;
        }
        p = 0;
        for (int j = 1; j <= (int)q[i].size(); ++j)
        {
            std::map<char, int>::iterator tmp = B.sam[p].to.find(q[i][q[i].size() - j]);
            if (tmp != B.sam[p].to.end())
            {
                p = tmp->second;
                if (B.sam[p].pos + end[q[i].size() - j] <= (int)s.size())
                {
                    ++ans;
                    break;
                }
            }
            else
                break;
        }
    }
    std::cout << ans << std::endl;
    return 0;
}