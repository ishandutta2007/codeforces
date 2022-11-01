#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <map>
#include <fstream>
#include <iostream>
#define forn(i, n) for(int i = 0; i < n; i++)
#define mp(i, j) make_pair(i, j)
#define rs(a, j) a.resize(j)
#define pb(a, j) a.push_back(j)
#define po_b(a) a.pop_back()
#define len(s) s.length()
#define sz(a) a.size()
typedef long long ll;
typedef long double ld;
using namespace std;
ll m, n, k,  pref1[1000001], pref2[1000001], kou, kou1, mid, j, p;
vector <long long> a;
vector <pair<ll, ll> > ans;
long binary(long l, long r, long k)
{
    while(r - l > 1)
    {
        mid = (l + r) / 2;
        if(pref1[mid] - pref1[j - 1] < k && pref2[mid] - pref2[j - 1] < k)
        {
            l = mid;
            continue;
        }
        r = mid;
    }
    return r;
}
int main()
{
    //ifstream cin("input.txt");
    cin >> n;
    a.resize(n + 100);
    pref1[0] = 0;
    pref2[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pref1[i] = pref1[i - 1];
        pref2[i] = pref2[i - 1];
        if(a[i] == 1)pref1[i] ++;
        if(a[i] == 2)pref2[i] ++;
    }
    bool ok;
    ll last;
    for(int i = 1; i <= n; i++)
    {
        ok = true;

        j = 1; kou = 0; kou1 = 0;
        while(j <= n)
        {
            if(pref1[n] - pref1[j - 1] < i && pref2[n] - pref2[j - 1] < i)
            {
                ok = false; break;
            }
            p = binary(j - 1, n, i);
            if(pref1[p] - pref1[j - 1] == i)
            {
                kou ++;
                last = 1;
            }
            else
            {
                kou1 ++;
                last = 2;
            }
            j = p + 1;
        }
        if(ok && kou != kou1)
        {
            if(last == 1 && kou > kou1) ans.push_back(mp(kou, i));
            if(last == 2 && kou1 > kou) ans.push_back(mp(kou1, i));
        }
    }
    sort(ans.begin(), ans.end());
    cout << sz(ans) << endl;
    forn(i, sz(ans))
    {
        cout << ans[i].first << " " << ans[i].second << endl;
    }
    return 0;
}