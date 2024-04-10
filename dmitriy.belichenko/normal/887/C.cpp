#include<iostream>
#include<math.h>
#include<cstring>
#include<set>
#include<algorithm>
#include<vector>
#include<map>
#include<iomanip>
#include<queue>
#include<string>
#include<ctime>
#include<bitset>
#include <unordered_set>
#include <unordered_map>
#include <cassert>
#define fst first
#define snd second
#define pb push_back
#define mp(x, y) make_pair(x, y)
#define sq(a) (long double)a * a
using namespace std;
typedef long long ll;
const int N = 100005;
pair<long long, int> t[400005], d[400005], t1[400005], t2[400005];
int a[6][2][2];
bool check(int i )
{
    for(int j = 0; j < 2; j++)
    {
        for(int k = 0; k < 2; k++)
        {
            if(a[i][j][k] != a[i][0][0]) return false;
        }
    }
    return 1;
}
int p[25];
int cnt = 0;
int main()
{
    srand(time(0));
    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            for(int k = 0; k < 2; k++)
            {

                cin >> a[i][j][k];
                p[++cnt] = a[i][j][k];
            }
        }
    }
    //  0 - 2 , 1 - 5 , 3 - 4
    if(check(0) && check(2))
    {
        vector<int> t = {13 , 14 , 5 , 6 , 17 , 18, 21 , 22};
        vector<int> q = t;
        for(auto &y : q)
        {
            y += 2;
        }
        vector<int> l;
        for(int i = 0; i < 8; i++)
        {
            l.pb(q[(i + 2) % 8]);
        }
        bool flag = 1;
        for(int i = 0; i < 4; i++)
        {
            int d1 = p[t[2 * i]];
            int d2 = p[t[2 * i + 1]];
            int d3 = p[l[2 * i]];
            int d4 = p[l[2 * i + 1]];
            if(d1 == d2 && d2 == d3 && d3 == d4 )
            {
                
            }
            else flag = 0;
        }
        if(flag)
        {
            cout << "YES" << "\n";
            return 0;
        }
        l.clear();
        for(int i = 0; i < 8; i++)
        {
            l.pb(q[(i + 6) % 8]);
        }
        flag = 1;
        for(int i = 0; i < 4; i++)
        {
            int d1 = p[t[2 * i]];
            int d2 = p[t[2 * i + 1]];
            int d3 = p[l[2 * i]];
            int d4 = p[l[2 * i + 1]];
            if(d1 == d2 && d2 == d3 && d3 == d4 )
            {
                
            }
            else flag = 0;
        }
        if(flag)
        {
            cout << "YES" << "\n";
            return 0;
        }

    }
    if(check(1) && check(5))
    {
        vector<int> t = {1 , 2 , 18 , 20 , 12 , 11, 15  , 13};
        vector<int> q = {3 ,4 , 17 , 19 , 10 , 9 , 16 , 14};
        vector<int> l;
        for(int i = 0; i < 8; i++)
        {
            l.pb(q[(i + 2) % 8]);
        }
        bool flag = 1;
        for(int i = 0; i < 4; i++)
        {
            int d1 = p[t[2 * i]];
            int d2 = p[t[2 * i + 1]];
            int d3 = p[l[2 * i]];
            int d4 = p[l[2 * i + 1]];
            if(d1 == d2 && d2 == d3 && d3 == d4 )
            {
                
            }
            else flag = 0;
        }
        if(flag)
        {
            cout << "YES" << "\n";
            return 0;
        }
        l.clear();
        for(int i = 0; i < 8; i++)
        {
            l.pb(q[(i + 6) % 8]);
        }
        flag = 1;
        for(int i = 0; i < 4; i++)
        {
            int d1 = p[t[2 * i]];
            int d2 = p[t[2 * i + 1]];
            int d3 = p[l[2 * i]];
            int d4 = p[l[2 * i + 1]];
            if(d1 == d2 && d2 == d3 && d3 == d4 )
            {
                
            }
            else flag = 0;
        }
        if(flag)
        {
            cout << "YES" << "\n";
            return 0;
        }
        
    }
    if(check(3) && check(4))
    {
        vector<int> t = {1 , 3 , 5 , 7 , 9 , 11, 24, 22};
        vector<int> q = {2 ,4 , 6 , 8 , 10 , 12 , 23 , 21};
        vector<int> l;
        for(int i = 0; i < 8; i++)
        {
            l.pb(q[(i + 2) % 8]);
        }
        bool flag = 1;
        for(int i = 0; i < 4; i++)
        {
            int d1 = p[t[2 * i]];
            int d2 = p[t[2 * i + 1]];
            int d3 = p[l[2 * i]];
            int d4 = p[l[2 * i + 1]];
            if(d1 == d2 && d2 == d3 && d3 == d4 )
            {
                
            }
            else flag = 0;
        }
        if(flag)
        {
            cout << "YES" << "\n";
            return 0;
        }
        l.clear();
        for(int i = 0; i < 8; i++)
        {
            l.pb(q[(i + 6) % 8]);
        }
        flag = 1;
        for(int i = 0; i < 4; i++)
        {
            int d1 = p[t[2 * i]];
            int d2 = p[t[2 * i + 1]];
            int d3 = p[l[2 * i]];
            int d4 = p[l[2 * i + 1]];
            if(d1 == d2 && d2 == d3 && d3 == d4 )
            {
                
            }
            else flag = 0;
        }
        if(flag)
        {
            cout << "YES" << "\n";
            return 0;
        }
        
    }
    cout << "NO" << "\n";
    return 0;
}