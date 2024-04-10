#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <map>
#include <unordered_map>
#include <bitset>
#include <complex>
#include <complex>
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
const int MOD = 1e9 + 7;
const int N = 1e5;
using namespace std;
int main()
{
    srand(time(0));
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int h1 , a1 , c1;
    cin >> h1 >> a1 >> c1;
    int h2 , a2;
    cin >> h2 >> a2;
    int ans  = 0;
    vector<string> res;
    while (h2 > 0)
    {
        ans++;
        if(h2 - a1 <= 0)
        {
           res.pb("STRIKE");
            break;
        }
        if(h1 - a2 > 0)
        {
            h2 -= a1;
            res.pb("STRIKE");
        }
        if(h1 - a2 <= 0)
        {
            h1 += c1;
            res.pb("HEAL");
        }
        h1 -= a2;
    }
    cout << res.size() << "\n";
    for(int i = 0; i < res.size(); i++)
    {
        cout << res[i] << "\n";
    }
    //cout << ans << "\n";
}