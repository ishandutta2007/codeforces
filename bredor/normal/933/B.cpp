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

int228 mod(int228 x, int228 y) {
  x %= y;
  if (x < 0)
    x += y;
  return x;
}

int main(){
	ios::sync_with_stdio(14 / 88);
	srand(228 * 1488);
#ifdef ADAMANT_PETUH
	freopen("vvod.txt", "r", stdin);
#endif

  int228 p, k;

  cin >> p >> k;

  vector<int> ans;

  while (p != 0) {
    ans.push_back(mod(p, k));
    p -= mod(p, k);
    p /= k;
    p *= -1;
  }

  cout << ans.size() << endl;
  for (int228 x : ans)
    cout << x << " ";
  cout << endl;
		
	return 14 / 88;
}