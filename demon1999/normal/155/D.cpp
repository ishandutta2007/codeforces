#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#define forn(i, n) for(int i = 0; i < n; i++)
#define pb(a, i) a.push_back(i)
#define m_p(i, j) make_pair(i, j)
#define sz(a) a.size()
#define rs(a, k) a.resize(k)
typedef long long ll;
typedef long double ld;
using namespace std;
ll l, r, n, m, p33;
map <int, int> q;
set <int> p;
set <int> :: iterator it;
bool ok = true;
int main()
{
    cin >> n >> m;
    vector <long> a(n + 1, 0);
    char k;
    for (int j = 0; j < m; j ++)
    {
        cin >> k >> r;
        if(k == '-')
        {
            if (a[r] != r)
            {
               cout << "Already off" << endl;
               continue;
            }                 
            else
            cout << "Success" << endl;
            for (int i = 1; i * i <= r; i++)
            {
                if(r % i == 0)
                {
                     if(i != 1)a[i] = 0;
                     a[r / i] = 0;
                }
            }
        }
        if(k == '+')
        {
             if (a[r] == r)
             {
                cout << "Already on" << endl;
                continue;
             }
             ok = true;
             for (int i = 1; i * i <= r; i++)
             {
                 if (r % i == 0 && (a[i] > 1 || a[r / i]  > 1))
                 {
                       ok = false;
                       cout << "Conflict with " << max(a[i], a[r / i]) << endl;
                       break;
                 }
             }
             if (ok)
             {
                cout << "Success" << endl;
                for (int i = 1; i * i <= r; i++)
                    if(r % i == 0)
                    {
                         if(i != 1) a[i] = r;
                         if( r / i != 1)a[r / i] = r;
                    }
                if(r == 1)a[1] = 1;
             }
        }
    }
    return 0;
}