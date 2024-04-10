
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

int axis[102];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n , a, b;
    cin >> n >> a >> b;
    for(int i = 0; i <= 1e7; i++)
    {
        if( (n - a * i) % b == 0 && n - a * i >= 0)
        {
            cout << "YES" << "\n";
            cout << i << " " <<  (n - a * i ) / b << "\n";
            return 0;
        }
    }
    cout << "NO" << "\n";
}