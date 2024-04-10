#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#define forn(i, n) for(ll i = 0; i < n; i++)
#define m_p(i, j) make_pair(i, j)
#define r_s(l1, j) l1.resize(j)
typedef long long ll;
using namespace std;
ll m, n, k = 0, t, q1, num;
vector<pair<ll, ll> > a;
vector<ll> a1, l1, r1, t1, l2;
map<ll, ll> ml;
int main()
{
    //ifstream cin("input.txt");
    cin >> m;
    r_s(l1, m);
    r_s(r1, m);
    r_s(t1, m);
    r_s(l2, m);
    forn(i, m)
    {
        cin >> t >> q1;
        if(t == 1)
        {
            ml[k] = q1;
            if(a1.size() < 100000)a1.push_back(q1);
            k++;
            l1[i] = k;
            r1[i] = k;
            continue;
        }
        cin >> t1[i];
        l2[i] = q1;
        l1[i] = k + 1;
        r1[i] = k + q1 * t1[i];
        k += q1 * t1[i];
        forn(j, t1[i])
        {
            if(a1.size() >= 100000)break;
            forn(q, q1)
                if(a1.size() >= 100000)break;
                else a1.push_back(a1[q]);
        }
    }
    cin >> n;
    forn(i, n)
    {
        cin >> num;
        if(num <= 100000)
        {
            cout << a1[num - 1] << " ";
            continue;
        }
        if(ml[num - 1] != 0)
        {
            cout << ml[num - 1] << " ";
            continue;
        }
        q1 = lower_bound(l1.begin(), l1.end(), num) - l1.begin();
        q1--;
        num -= l1[q1];
        num %= l2[q1];
        cout << a1[num] << " ";
    }
    return 0;
}