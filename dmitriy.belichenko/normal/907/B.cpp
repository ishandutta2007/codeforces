
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
bitset<100> u;
int axis[102];
int ind(char c)
{
    return c - 'a';
}
const int maxn = 26;
char field[100][100];
bool check(int x , int y)
{
    x = (x - 1) % 3;
    y = (y - 1) % 3;
    bool ok = false;
    for (int i = 3 * y; i < 3 + y * 3; i++)
    {
        for (int j = 3 * x; j < 3 + x * 3 ; j++)
        {
            if (field[i][j] == '.')
            {
                field[i][j] = '!';
                ok = true;
            }
        }
    }
    return ok;
}
void output()
{
    for (int i = 0; i< 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << field[i][j];
            if((j + 1) % 3 == 0)
            {
                cout << " ";
            }
        }
        if ((i + 1) % 3 == 0)
        {
            cout << "\n";
        }
        cout << "\n";
    }

}
int ok = 0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int x, y;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> field[i][j];
        }
    }
    cin >> x >> y; // y x
    swap(x , y);
    if (!check(x , y))
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (field[i][j]=='.') field[i][j] = '!';
            }
        }
    }
    if(x == -1)
    {
        output();
    }
    output();
       return 0;
}