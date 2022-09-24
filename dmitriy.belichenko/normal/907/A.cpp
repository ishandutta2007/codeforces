
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <map>
#include <unordered_map>
#include <bitset>
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
#define ll long long
const int MOD = 2e9 + 7;
const int N = 3e5;
using namespace std;
vector<ll>sqr;
map<string,vector<string>> tk;
int axis[102];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int a , b , c , d;
    cin >> a >> b >> c >> d;
    for (int i = 1; i <= 400; i++)
    {
        for (int j = 1; j <= 400; j++)
        {
            for (int k = 1; k <= 400; k++)
            {
                if (i > j && j > k && a <= i && j >= b && k >= c && 2 * a >= i && 2 * b >= j && 2 * c>= k && d <= k && 2 * d >=k)
                {
                    if(2 * d < j)
                    {
                        cout << i << "\n" << j << "\n" << k << "\n";
                        return 0;
                    }
                }
            }
        }
    }
    cout<<-1;
}