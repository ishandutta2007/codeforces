#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <map>
#define forn(i, n) for(int i = 0; i < n; i++)
#define m_p(i, j) make_pair(i, j)
#define r_s(a, j) a.resize(j)
#define p_b(a, j) a.push_back(j)
#define po_b(a) a.pop_back()
#define len(s) s.length()
#define sz(a) a.size()
typedef long long ll;
using namespace std;

long long mi = -1, hp1, atk1, def1, hp2, atk2, def2, h, a, d, q, i12, j12, k12, q1, q2, mh;
int main()
{
    cin >> hp1 >> atk1 >> def1 >> hp2 >> atk2 >> def2 >> h >> a >> d;
    q = max(atk1, def2 + 1);
    for(ll i = 0; i <= 10000; i ++)
    {
        for(long long j = q; j <= 200; j++)
            for(ll k = 0; k <= 100; k++)
            {
                q1 = 0; q2 = 0;
                if(atk2 - def1 - k > 0 && (hp1 + i) %  (atk2 - def1 - k) > 0)q1 = 1;
                if(hp2 % ( j - def2) > 0)q2 = 1;
                if(atk2 - def1 - k <= 0 || (hp1 + i) / (atk2 - def1 - k) + q1 > hp2 / (j - def2) + q2)
                {
                    if(mi == -1 || mi > i * h + (j- atk1) * a + k * d)
                    {
                        mi = i * h + (j - atk1) * a + k * d;
                        i12 = i + hp1;
                        j12 = j;
                        k12 = k + def1;
                    }
                    break;
                }
            }
    }
    cout << mi << endl;
    return 0;
}