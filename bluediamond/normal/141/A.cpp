#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
using namespace std;

#define f(i, a, b) for(int i = a; i < b; i++)
#define rep(i, n)  f(i, 0, n)

typedef long long ll;

int main() {
  string s1, s2, s3;
  cin >> s1 >> s2 >> s3;
  string t = s1 + s2;
  sort(t.begin(), t.end());
  sort(s3.begin(), s3.end());
  cout << ((t == s3) ? "YES" : "NO") << endl;
}