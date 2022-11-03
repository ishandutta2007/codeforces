#include <iomanip>
#include <vector>
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <fstream>
#include <set>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<ll> vll;
typedef vector<string> vs;
const ll MD = 10007;
const double PI = 3.1415926535;
const int MAX_INT = (int)1e9;
const ll MAX_LL = (long long)1e18;

int gcd(int x, int y)
{
    while (x>0 && y>0)
          if (x>=y)
             x %= y;
          else
              y %= x;
    return x+y;
}

int main()
{
    int n,m;
    cin >> n >> m;
    n++;
    m++;
    vi a,b;
    a.resize(n);
    b.resize(m);
    for (int i=0;i<n;i++)
        cin >> a[i];
    for (int i=0;i<m;i++)
        cin >> b[i];
    if (n>m)
    {
       if (a[0]*b[0]<0)
          cout << "-";
       cout << "Infinity";
    }else
    if (m>n)
       cout << "0/1";
    else
    {
        int k = gcd(abs(a[0]),abs(b[0]));
        a[0] /= k;
        b[0] /= k;
        if (b[0]<0)
        {
                   a[0] *= -1;
                   b[0] *= -1;
        }
        cout << a[0] << "/" << b[0];
    }
    cin >> n;
            
    return 0;
}