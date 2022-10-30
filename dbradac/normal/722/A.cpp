#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

void Stavi(string &s, int x)
{
  s.push_back('0' + (x / 10));
  s.push_back('0' + (x % 10));
}

int Raz(string a, string b)
{
  int l = (int) a.size();
  int r = 0;

  for (int i=0; i<l; i++)
    if (a[i] != b[i])
      r++;

  return r;
}

int main()
{
  int f;
  string s;

  cin >> f >> s;

  int d = 0, g = 23;
  if (f == 12) {
    d = 1;
    g = 12;
  }

  int rje = 234234;
  string ss = "";
  for (int i=d; i<=g; i++) {
    for (int j=0; j<60; j++) {
      string tmp = "";
      Stavi(tmp, i);
      tmp += ":";
      Stavi(tmp, j);
      if (Raz(tmp, s) < rje) {
        ss = tmp;
      }
      rje = min(rje, Raz(tmp, s));
    }
  }

  cout << ss << endl;

  return 0;
}