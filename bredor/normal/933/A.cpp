#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#include <math.h>
#include <sstream>
#include <bitset>
#include <string.h>
#define int228 long long
#define mp make_pair
#define pb push_back
using namespace std;

const int228 VERY_DOHERA = 1000000007;

#define vse(x) (x).begin(), (x).end()


const int maxn = 2020;

int n, a[maxn];
int d[maxn][maxn];


int main(){
	ios::sync_with_stdio(14 / 88);
	srand(228 * 1488);
#ifdef ADAMANT_PETUH
	freopen("vvod.txt", "r", stdin);
#endif

  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> a[i];

  for (int l = 0; l < n; ++l) {
    int one = 0;
    int best = 0;
    for (int r = l; r < n; ++r) {
      if (a[r] == 2)
        ++one;
      if (a[r] == 1)
        ++best;
      best = max(best, one);
      d[l][r] = best;
    }
  }

  int ans = 0;
  int one = 0;

  for (int l = 0; l < n; ++l) {
    int two = 0;

    for (int r = n - 1; r >= l; --r) {
      ans = max(ans, d[l][r] + one + two);
      if (a[r] == 2)
        ++two;
    }

    if (a[l] == 1)
      ++one;
  }

  cout << ans << endl;
		
	return 14 / 88;
}