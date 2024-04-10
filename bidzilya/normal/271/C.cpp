#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <vector>
#include <string>
#include <iomanip>
#include <deque>
using namespace std;

typedef long long ll;
const ll MD = (ll)1e9 + 9;
const double PI = 3.1415926535;
const int MAX_INT = (int)1e9;
const ll MAX_LL = (ll)1e18;
const double eps = 1e-8;

int n,k;
int a[1111111];

int main(){
    cin >> n >> k;
    if (n < 3*k){cout << -1 << endl; return 0;}
    int x = 1;
    for (int i=0; i<k/2; i++)
    {
        int c1 = i*2+1;
        int c2 = (i+1)*2;
        a[x] = c1;
        a[x+1] = c1;
        a[x+3] = c1;
        a[x+2] = c2;
        a[x+4] = c2;
        a[x+5] = c2;
        x += 6;
    }
    if (k%2 == 1)
    {
        if (x+2 == n)
        {
            a[x-1] = k;
            a[x] = k;
            a[x+2] = k;
            a[x+1] = k-1;
            x += 3;
        }else
        {
            a[x] = k;
            a[x+1] = k;
            a[x+2] = 1;
            a[x+3] = k;
            x += 4;
        }
    }
    while (x <= n)
    {
        a[x] = 1;
        x++;
    }
    for (int i=1; i<=n; i++)
        cout << a[i] << " ";
    cout << endl;

    return 0;
}