#include <string>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl
#define REP(i, n) for (int i=0; i<n; i++)
#define FOR(i, a, b) for (int i=(a); i<(b); i++)
#define _ << " " <<

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

int main()
{
  string a, b;
  cin >> a >> b;
  int n;
  cin >> n;

  cout << a << " " << b << endl;

  for (; n--; ) {
    string x, y;
    cin >> x >> y;
    if (x == a) a = y;
    if (x == b) b = y;
    cout << a << " " << b << endl;
  }

  return 0;
}