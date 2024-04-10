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
//#include "optimization.h"
#include<bitset>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
typedef long long ll;
using namespace std;
const int N =  5e5 + 1000;
ll INF = (1LL << 62) - 1;
ll MOD = 1e9 + 7;


pair<char, int> c[N];
int st[400], n;
int ans[3];
void calcans()
{
    for (int i = 0; i < 10; ++i)
    {
        if (!st[i])
        {
            ans[2] += 1 << i;
        }
        if (st[i] == 1)
        {
            ans[1] += 1 << i;
        }
        if (st[i] == 2)
        {
            ans[0] -= 1 << i;
        }
    }

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
            cin >> c[i].first >> c[i].second;
    }
    int zero = 0;
    for (int i = 0; i < n; ++i)
    {
        if (c[i].first == '^')
        {
            zero ^= c[i].second;
        }
        else
            if (c[i].first == '|')
            {
                zero |= c[i].second;
            } else {
                zero &= c[i].second;
            }
    }

    for (int i = 0; i < 10; ++i)
    {
        int one = 1 << i;
        for (int i = 0; i < n; ++i)
        {
            if (c[i].first == '^')
            {
                one ^= c[i].second;
            }
            else
                if (c[i].first == '|')
                {
                    one |= c[i].second;
                }
                else
                {
                    one &= c[i].second;
                }
        }

        int zp = (zero >> i) & 1;
        int op = (one >> i) & 1;
        if (zp == 1 && op == 0)
        {
                st[i] = 0;
            }
            else if (zp == 1 && op == 1)
            {
                st[i] = 1;
            }
            else if (zp == 0 && op == 0)
            {
                st[i] = 2;
            } else
            {
                st[i] = 3;
            }
        
}
        ans[0] = 1023;
    calcans();
    cout << 3 << "\n";
    cout << "& " << ans[0] << "\n";
    cout << "| " << ans[1] << "\n";
    cout << "^ " << ans[2] << "\n";
    cout << endl;

    return 0;
}