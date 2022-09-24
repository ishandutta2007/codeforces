#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <math.h>
#include <stack>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <deque>
#include <bitset>
#define ull unsigned long long
#define ll long long
#define ld long double
#define MAX 2e9
#define MIN -2e9
#define PI 3.14159265
#define fst first
#define scd second
#define mp make_pair
#define forn(i, x) for(int i = 0; i < x; i++)
#define pb push_back
ull INF = 1e9 + 7;

using namespace std;


using namespace std;

int a[100], b[100];

int main()
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    int m;
    for (int i = 0; i < n; i++)
    {
        cin >> m;
        a[m]++;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> m;
        b[m]++;
    }
    int aa=0, bb=0;
    for (int i = 1; i <= 5; i++)
    {
        int sum = a[i] + b[i];
        if (sum % 2 == 1)
        {
            cout << -1;
            exit(0);
        }
        else
        {
            if (a[i] > b[i]) bb += a[i] - sum / 2;
            else aa += b[i] - sum / 2;
        }
    }
    if (aa == bb) cout << aa;
    else cout << -1;
}