#include <iostream>
#include <map>
#include <vector>
#include <deque>
#include <algorithm>
#include <bitset>
#include <math.h>
#include <string>
#include <set>
using namespace std;
#define pb push_back
#define ll long long
#define mp make_pair
#define fst first
#define snd second
const double PI = acos(-1);
const int N = 100;
const int MOD = 1e9 + 7;
int sum(int a , int b)
{
    a += b;
    if(a < 0)
        return  a + MOD;
    if(a >= MOD)
        return a - MOD;
    else return a;
}

long long mult( long long a , long long b)
{
    long long c = 1LL * a * b;
    return c % MOD;
}
int poww(long long a , long long b)
{
    long long res = 1;
    a %= MOD;
    while(b > 0)
    {
        if(b % 2) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res % MOD;
}
set<char> gl = { 'a', 'e', 'i', 'o' , 'u' };
set<char> ch = { '1', '3', '5', '7' ,'9' };
int n , m;

char field[N][N];
const int dx[4] = { -1, 0, 1, 0 };
const int dy[4] = { 0, 1, 0, -1 };
bool ok(int i, int j)
{
    if (i > n || j > m || i < 1 || j < 1 || field[i][j] == '#') return 0;
    return 1;
}
int ind(char c)
{
    return c - '0';
}
int x = 0, y = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector <int> a = { 0 , 1 , 2 , 3 };
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> field[i][j];
        }
    }
    int ans = 0 , nowx = 0, nowy = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (field[i][j] == 'S' && !x && !y)
            {
                x = i;
                nowx = x;
                y = j;
                nowy = y;
            }
        }
    }
    string s;
    cin >> s;
    while (true)
    {
        x = nowx;
        y = nowy;
        for (auto p : s)
        {
            x += dx[a[ind(p)]];
            y += dy[a[ind(p)]];
            if (ok(x, y));
            else break;
            
            if (field[x][y] == 'E')
            {
                ans++;
                break;
            }
        }
        if(!next_permutation(a.begin(), a.end())) break;
    }
    cout << ans << endl;
    return 0;
}