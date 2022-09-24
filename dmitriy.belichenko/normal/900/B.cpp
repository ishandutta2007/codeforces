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
map<pair<int, int> , int> cnt;
int main()
{
    srand(time(0));
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a , b , c;
    cin >> a >> b >> c;
    if(a % b == 0 && c == 0)
    {
        cout << 1 << "\n";
        return 0;
    }

    if(a > b) a = a % b;
    int j = 0;
    for(int i = 0; i < 2 * 100000 + 10; i++)
    {
        int d = 10;
        while(a < b)
        {
            if(c == d)
            {
                cout << i << "\n";
                return 0;
            }
            if(a * 10 < b)
            {
              i++;
                d = 0;
            }
        
            a *= 10;
        }
        if(c == d)
        {
            cout << i + 1<< "\n";
            return 0;
        }
        if(a >= b)
        {
            d = a / b;
            a = a % b;
        }
        if(c == d)
        {
            cout << i + 1;
            return 0;
        }
        if(a == 0 && c == 0)
        {
            cout << i  + 2 << "\n";
            return 0;
        }
        if(a == 0) break;
    }
    cout << -1;
    return 0;
    
}