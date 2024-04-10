#include <fstream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <iostream>
#include <map>
#define forn(i, n) for(ll i = 0; i < n; i++)
#define m_p(i, j) make_pair(i, j)
#define r_s(a, j) a.resize(j)
#define p_b(a, j) a.push_back(j)
#define po_b(a) a.pop_back()
#define len(s) s.length()
#define sz(a) a.size()
typedef long long ll;
using namespace std;
ll n, x, y, n1, q, q1, k, bal, bal1;
vector <ll> ans;
string a, s = "";
int main()
{
    //ifstream cin("input.txt");
    cin >> a;
    bal = 0;

    bal1 = 0;
    for(int i = len(a) - 1; i >=0; i--)
    {
        if(a[i] == '(')bal1 --;
        if(a[i] == ')')bal1 ++;
        if(bal1 < 0)
        {
            cout << -1;
            return 0;
        }
        if(a[i] == '#')
        {
            q = i;
            break;
        }
    }
    for(int i = 0; i < q; i++)
    {
        if(a[i] == '#')
        {
            a[i] = ')';
            ans.push_back(1);
        }
    }
    for(int i = 0; i < len(a); i++)
    {
        if(a[i] == '(')bal ++;
        if(a[i] == ')')bal --;
        if(bal < 0)
        {
            cout << -1;
            return 0;
        }
        if(a[i] == '#')
        {
            ans.push_back(bal - bal1);
            if(bal - bal1 <= 0)
            {
                cout << -1;
                return 0;
            }
            bal = bal1;
        }
    }
    for(int i = 0; i < sz(ans); i++)cout << ans[i] << endl;
    return 0;
}