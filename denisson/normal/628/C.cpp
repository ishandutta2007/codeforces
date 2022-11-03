/*#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:256000000")
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
*/
#include <bits/stdc++.h>

#define ll long long
#define str string
#define db long double
#define XX first
#define YY second
#define vec vector
#define re return
#define y1 dasfasdf32s23s3224
#define LN '\n'
#define all(a) a.begin(), a.end()
#define in insert
#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < n; i++)
#define form(i, a, b) for (int i = a; i <= b; i++)

const int INF = 1e9 + 7;
const ll LINF = 1e18 + 7;
const ll P = 997;
const ll nothing = LINF + 1;
const int MOD = 1e9 + 7;
const int MOD1 = 1e9 + 7;
const int MOD2 = 1e9 + 5;
const bool is_testing = 0;
const int MAXN = 50000;

using namespace std;

int n, k;
str s;

int rast(char c1, char c2)
{
    re (abs(c1 - c2));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie();
    //freopen("q1.txt", "r", stdin);
    //freopen("q3.txt", "w", stdout);
    if (is_testing)
    {
        freopen("input.txt", "r", stdin);
    }

    cin >> n >> k >> s;
    str s1 = "";
    forn(i, s.size())
    {
        if (k == 0)
        {
            s1 += s[i];
            continue;
        }
        int t = max(rast(s[i], 'a'), rast(s[i], 'z'));
        if (k >= t)
        {
            k -= t;
            if (rast(s[i], 'a') > rast(s[i], 'z'))
                s1 += 'a';
            else
                s1 += 'z';
        }
        else
        {
            if (k <= rast(s[i], 'z'))
                s1 += (char)(s[i] + k);
            else
            {
                s1 += (char)(s[i] - k);
            }
            k = 0;
        }
    }
    if (k == 0)
        cout << s1;
    else
        cout << -1;
}