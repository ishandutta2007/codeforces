#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <map>
#include <unordered_map>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <math.h>
#include <cstring>
#include <queue>
#include <set>
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
#define ll long long
const int MOD = 1e9 + 7;
const int N = 3e5;
using namespace std;
vector<ll> a;
int dp1[N] , dp2[N];
int pref[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n , m;
    cin >> n;
    string s;
    cin >> s;
    cin >> m;
    if(s[0] == '?') pref[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        pref[i] = pref[i - 1];
        if(s[i - 1] == '?')
        pref[i]++;
    }
    int an = n, bn = n, ac = n, bc = n;
    for (int i = n - 1; i >= 0; i--)
    {
        pair<int, int> cur;
        int r;
        if (i % 2 == 1)
        {
            r = min(bn, ac) - i;
            if (s[i] == 'a')
            {
                an = i;
            }
            else if (s[i] == 'b')
            {
                bn = i;
            }
        }
        else
        {
            r = min(an, bc) - i;
            if (s[i] == 'a')
            {
                ac = i;
            }
            else if (s[i] == 'b')
            {
                bc = i;
            }
        }
        if (s[i] != 'b' && r >= m)
        {
            dp1[i] = dp1[i + m] + 1;
            dp2[i] = dp2[i + m] - (pref[i + m] - pref[i]);
        }
        cur = { dp1[i] , dp2[i]};
        cur = max(cur, {dp1[i + 1] , dp2[i + 1]});
        dp1[i] = cur.fst;
        dp2[i] = cur.second;
    }
    cout << -dp2[0] << endl;
    return 0;
}