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

typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;

const int maxn = 103;

int n, cnt[maxn], pos[maxn];

int main()
{
  scanf("%d", &n);
  forn(i, n)
  {
    int a;
    scanf("%d", &a);
    cnt[a & 1]++, pos[a & 1] = i;
  }

  printf("%d\n", (cnt[0] > cnt[1] ? pos[1] : pos[0]) + 1);
  return 0;
}