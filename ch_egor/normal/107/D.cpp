#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <cassert>
#include <algorithm>
#include <iomanip>
#include <ctime>
#include <cmath>

#pragma comment(linker, "/STACK:256000000")

using namespace std;

typedef long long int int64;
typedef long double double80;

const int INF = (1 << 29) + 5;
const int MOD = 12345;
const int MAX_C = 26;
const int MULT = 123 + 5;

struct point
{
    int at;
    int lc;
    int nk;

    point(int _at, int _lc, int _nk)
    {
        at = _at;
        lc = _lc;
        nk = _nk;
    }
};

int64 n;
int c;
int nk, ad;
vector<point> get_by;
vector<int> arr[MAX_C];
int dp[MAX_C];
int lcm[MAX_C];
int ans[MULT];
int mp[MULT][MULT];
int buff2[MULT][MULT];
int buff1[MULT];

int gcd(int a, int b)
{
    if (a < b)
    {
        swap(a, b);
    }

    int c;
    while (a % b != 0)
    {
        c = a;
        a = b;
        b = c%b;
    }

    return b;
}

void mult_all()
{
    for (int i = 0; i < MULT; ++i)
    {
        buff1[i] = 0;
        for (int j = 0; j < MULT; ++j)
        {
            buff1[i] += (mp[j][i] * ans[j]) % MOD;
            buff1[i] %= MOD;
        }
    }

    for (int i = 0; i < MULT; ++i)
    {
        ans[i] = buff1[i];
    }
}

void mult_mp()
{
    for (int i = 0; i < MULT; ++i)
    {
        for (int j = 0; j < MULT; ++j)
        {
            buff2[i][j] = 0;
            for (int q = 0; q < MULT; ++q)
            {
                buff2[i][j] += (mp[i][q] * mp[q][j]) % MOD;
                buff2[i][j] %= MOD;
            }
        }
    }

    for (int i = 0; i < MULT; ++i)
    {
        for (int j = 0; j < MULT; ++j)
        {
            mp[i][j] = buff2[i][j];
        }
    }
}


int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    scanf("%I64d %d\n", &n, &c);

    char type;
    int add;
    for (int i = 0; i < c; ++i)
    {
        scanf("%c %d\n", &type, &add);
        arr[type - 'A'].push_back(add);
    }

    int lc;
    vector<int> new_arr;
    for (int i = 0; i < MAX_C; ++i)
    {
        lcm[i] = 0;

        if (arr[i].size() != 0)
        {
            sort(arr[i].begin(), arr[i].end());
            new_arr.clear();

            new_arr.push_back(arr[i][0]);
            for (int j = 1; j < arr[i].size(); ++j)
            {
                if (arr[i][j] != arr[i][j - 1])
                {
                    new_arr.push_back(arr[i][j]);
                }
            }
            arr[i].swap(new_arr);

            lc = 1;
            for (int j = 0; j < arr[i].size(); ++j)
            {
                lc = (lc*arr[i][j]) / gcd(lc, arr[i][j]);
            }
            lcm[i] = lc;
        }
    }

    nk = 1;

    for (int i = 0; i < MAX_C; ++i)
    {
        if (lcm[i] != 0)
        {
            get_by.push_back(point(i, lcm[i], nk));
            nk *= lcm[i];
        }
    }

    int at;
    for (int i = 0; i < nk; ++i)
    {
        for (int j = 0; j < get_by.size(); ++j)
        {
            at = (i / get_by[j].nk) % get_by[j].lc;
            ++mp[i][i - at*get_by[j].nk + ((at + 1) % get_by[j].lc)*get_by[j].nk];
        }
    }

    ans[0] = 1;
    while (n != 0)
    {
        if (n & 1)
        {
            mult_all();
            --n;
        }
        mult_mp();
        n >>= 1;
    }

    int answer = 0;
    bool good;
    for (int i = 0; i < nk; ++i)
    {
        for (int j = 0; j < get_by.size(); ++j)
        {
            good = false;
            at = (i / get_by[j].nk) % get_by[j].lc;
            for (int k = 0; k < arr[get_by[j].at].size(); ++k)
            {
                if (at % arr[get_by[j].at][k] == 0)
                {
                    good = true;
                    break;
                }
            }
            if (!good)
            {
                ans[i] = 0;
                break;
            }
        }
        answer += ans[i];
        answer %= MOD;
    }

    printf("%d", answer);

    fclose(stdin);
    fclose(stdout);

    return 0;
}