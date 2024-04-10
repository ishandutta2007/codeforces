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
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x;
        bool flag = 0;
        cin >> x;
        for(int i = 0; i < 100; i++)
        {
            for(int j = 0; j < 100; j++)
            {
                if(i * 3 + j * 7 == x)
                {
                    flag = 1;
                    break;
                }
            }
        }
        if(flag) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
    
}