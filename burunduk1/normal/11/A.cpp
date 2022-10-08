#include <cmath>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>

#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <functional>
#include <map>
#include <set>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define forit(i, a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define zero(a) memset(a, 0, sizeof(a))
#define pb push_back
#define mp make_pair

typedef unsigned long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;

int main()
{
  ll n, d, a, last = 0, res = 0;
  cin >> n >> d;
  forn(i, n)
  {
    cin >> a;
    if (a <= last)
    {
      ll k = (last - a) / d + 1;
      res += k, a += d * k;
    }
    last = a;
  }
  cout << res << endl;
  return 0;
}