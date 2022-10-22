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
#include <random>
#include <chrono>
// #include<windows.h>
// #define debug true
#define int long long
#define double long double
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int n;
enum FUCKCCF
{
    Num,
    And,
    Xor,
    Or,
    Not
};
struct node
{
    FUCKCCF type;
    bool Val, ans;
    vector<int> son;
    int fa;
} a[1000005];
string s;
int root;
void init(int now)
{
    switch (a[now].type)
    {
    case And:
        init(a[now].son[0]);
        init(a[now].son[1]);
        a[now].Val = a[a[now].son[0]].Val & a[a[now].son[1]].Val;
        break;
    case Xor:
        init(a[now].son[0]);
        init(a[now].son[1]);
        a[now].Val = a[a[now].son[0]].Val ^ a[a[now].son[1]].Val;
        break;
    case Or:
        init(a[now].son[0]);
        init(a[now].son[1]);
        a[now].Val = a[a[now].son[0]].Val | a[a[now].son[1]].Val;
        break;
    case Not:
        init(a[now].son[0]);
        a[now].Val = !a[a[now].son[0]].Val;
        break;
    case Num:
        break;
    }
}
void dfs(int now)
{
    switch (a[now].type)
    {
    case And:
        if (a[now].Val != (!a[a[now].son[0]].Val & a[a[now].son[1]].Val))
        {
            dfs(a[now].son[0]);
        }
        if (a[now].Val != (a[a[now].son[0]].Val & !a[a[now].son[1]].Val))
        {
            dfs(a[now].son[1]);
        }
        break;
    case Xor:
        if (a[now].Val != (!a[a[now].son[0]].Val ^ a[a[now].son[1]].Val))
        {
            dfs(a[now].son[0]);
        }
        if (a[now].Val != (a[a[now].son[0]].Val ^ !a[a[now].son[1]].Val))
        {
            dfs(a[now].son[1]);
        }
        break;
    case Or:
        if (a[now].Val != (!a[a[now].son[0]].Val | a[a[now].son[1]].Val))
        {
            dfs(a[now].son[0]);
        }
        if (a[now].Val != (a[a[now].son[0]].Val | !a[a[now].son[1]].Val))
        {
            dfs(a[now].son[1]);
        }
        break;
    case Not:
        dfs(a[now].son[0]);
        break;
    case Num:
        a[now].ans = true;
        break;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> s;
        if (s == "IN")
        {
            a[i].type = Num;
            cin >> a[i].Val;
        }
        if (s == "AND")
        {
            a[i].type = And;
            a[i].son.assign(2, 0);
            cin >> a[i].son[0] >> a[i].son[1];
            a[a[i].son[0]].fa = i;
            a[a[i].son[1]].fa = i;
        }
        if (s == "OR")
        {
            a[i].type = Or;
            a[i].son.assign(2, 0);
            cin >> a[i].son[0] >> a[i].son[1];
            a[a[i].son[0]].fa = i;
            a[a[i].son[1]].fa = i;
        }
        if (s == "NOT")
        {
            a[i].type = Not;
            a[i].son.assign(1, 0);
            cin >> a[i].son[0];
            a[a[i].son[0]].fa = i;
        }
        if (s == "XOR")
        {
            a[i].type = Xor;
            a[i].son.assign(2, 0);
            cin >> a[i].son[0] >> a[i].son[1];
            a[a[i].son[0]].fa = i;
            a[a[i].son[1]].fa = i;
        }
    }
    init(1);
    dfs(1);
    for (int i = 1; i <= n; ++i)
    {
        if (a[i].type == Num)
        {
            cout << (a[i].ans ^ a[1].Val);
        }
    }
    cout << endl;
    return 0;
}