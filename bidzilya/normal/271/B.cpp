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

bool isPrime(int x)
{
    if (x == 1)return false;
    for (int i=2; i<=sqrt(x); i++)
        if (x%i == 0)
            return false;
    return true;
}

int b[100001];
int str[500],stl[500];
int n,m;

int main(){
    int l = 1e5 + 3;
    for (int i=100000; i>=1; i--)
    {
        if (isPrime(i))
            l = i;
        b[i] = l-i;
    }
    cin >> n >> m;
    for (int i=0; i<n; i++)
        str[i] = 0;
    for (int j=0; j<m; j++)
        stl[j] = 0;
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
        {
            int x;
            cin >> x;
            str[i] += b[x];
            stl[j] += b[x];
        }
    int mn = str[0];
    for (int i=1; i<n; i++)
        mn = min(mn, str[i]);
    for (int j=0; j<m; j++)
        mn = min(mn, stl[j]);
    cout << mn << endl;

    return 0;
}