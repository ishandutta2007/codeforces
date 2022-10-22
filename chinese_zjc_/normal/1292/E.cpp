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
const char c[] = {'C', 'H', 'O'};
std::vector<int> query(std::string q)
{
    static int size;
    static std::vector<int> res;
    std::cout << "? " << q << std::endl;
    std::cin >> size;
    res.resize(size);
    for (int i = 0; i != size; ++i)
        std::cin >> res[i];
    return res;
}
void submit(std::string a)
{
    std::cout << "! " << a << std::endl;
}
void replace(std::string &str, int pos, std::string in)
{
    for (int i = 0; i != in.length(); ++i)
        str[pos - 1 + i] = in[i];
}
void solve4()
{
    static std::vector<int> tmp;
    std::string ans(4, ' ');
    tmp = query("CH");
    for (int i = 0; i != tmp.size(); ++i)
        replace(ans, tmp[i], "CH");
    tmp = query("CO");
    for (int i = 0; i != tmp.size(); ++i)
        replace(ans, tmp[i], "CO");
    if (ans != "    ")
    {
        for (int i = 0; i != 81; ++i)
        {
            std::string now;
            for (int j = 0, k = 1; j != 4; ++j, k *= 3)
                now += c[i / k % 3];
            bool canask = true;
            for (int j = 0; j != 4; ++j)
                if (ans[j] != ' ' && ans[j] != now[j])
                {
                    canask = false;
                    break;
                }
            if (canask && !query(now).empty())
                return submit(now);
        }
    }
    tmp = query("HO");
    for (int i = 0; i != tmp.size(); ++i)
        replace(ans, tmp[i], "HO");
    tmp = query("OH");
    for (int i = 0; i != tmp.size(); ++i)
        replace(ans, tmp[i], "OH");
    if (ans != "    ")
    {
        for (int i = 4; --i;)
            if (ans[i - 1] == ' ')
                ans[i - 1] = ans[i];
        int lst = ans.find_last_of("OH");
        for (int i = lst; i != 4; ++i)
            if (!query(ans.substr(0, lst + 1) + std::string(i - lst, ans[lst]) + std::string(4 - i - 1, 'C')).empty())
                return submit(ans.substr(0, lst + 1) + std::string(i - lst, ans[lst]) + std::string(4 - i - 1, 'C'));
    }
    tmp = query("OOO");
    for (int i = 0; i != tmp.size(); ++i)
        replace(ans, tmp[i], "OOO");
    tmp = query("HHH");
    for (int i = 0; i != tmp.size(); ++i)
        replace(ans, tmp[i], "HHH");
    tmp = query("CCC");
    for (int i = 0; i != tmp.size(); ++i)
        replace(ans, tmp[i], "CCC");
    if (ans == " CCC")
        return submit(query("OCCC").empty() ? "HCCC" : "OCCC");
    if (ans != "    ")
    {
        for (int i = 0; i != 4; ++i)
            if (ans[i] == ' ')
                ans[i] = 'C';
        return submit(ans);
    }
    return submit(query("OOCC").empty() ? "HHCC" : "OOCC");
}
void solve(int n)
{
    static std::vector<int> tmp;
    std::string ans(n, ' ');
    tmp = query("CH");
    for (int i = 0; i != tmp.size(); ++i)
        replace(ans, tmp[i], "CH");
    tmp = query("CO");
    for (int i = 0; i != tmp.size(); ++i)
        replace(ans, tmp[i], "CO");
    tmp = query("CC");
    for (int i = 0; i != tmp.size(); ++i)
        replace(ans, tmp[i], "CC");
    tmp = query("HO");
    for (int i = 0; i != tmp.size(); ++i)
        replace(ans, tmp[i], "HO");
    tmp = query("OH");
    for (int i = 0; i != tmp.size(); ++i)
        replace(ans, tmp[i], "OH");
    for (int i = 1; i != n - 1; ++i)
        if ((ans[i - 1] == 'O' || ans[i - 1] == 'H') && ans[i] == ' ')
            ans[i] = ans[i - 1];
    for (int i = n - 1; --i;)
        if ((ans[i] == 'O' || ans[i] == 'H') && ans[i - 1] == ' ')
            ans[i - 1] = ans[i];
    int len = std::min(size_t(n - 1), ans.find_first_of("CHO"));
    if (query(std::string(len, 'H') + ans.substr(len, n - 1 - len)).empty())
        replace(ans, 1, std::string(len, 'O'));
    else
        replace(ans, 1, std::string(len, 'H'));
    tmp = query(ans.substr(0, n - 1) + 'C');
    for (int i = 0; i != tmp.size(); ++i)
        replace(ans, tmp[i], ans.substr(0, n - 1) + 'C');
    for (int i = 1; i != n; ++i)
        if ((ans[i - 1] == 'O' || ans[i - 1] == 'H') && ans[i] == ' ')
            ans[i] = ans[i - 1];
    return submit(ans);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    int T, n;
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        if (n == 4)
            solve4();
        else
            solve(n);
        std::cin >> n;
    }
    return 0;
}