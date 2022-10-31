#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < int(n); ++i)
#define REPE(i, a, b) for (int i = (a); i <= int(b); ++i)
#define SZ(x) ((int)(x).size())
#define ALL(x) x.begin(), x.end()
#define PB push_back
#define EB emplace_back
using LL = long long;
using PII = pair<int, int>;
#define F first
#define S second

string a[20] = {"zero",    "one",     "two",       "three",    "four",
                "five",    "six",     "seven",     "eight",    "nine",
                "ten",     "eleven",  "twelve",    "thirteen", "fourteen",
                "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
string b[10] = {"zero",  "ten",   "twenty",  "thirty", "forty",
                "fifty", "sixty", "seventy", "eighty", "ninety"};

int main() {
  int n;
  cin >> n;
  if (n < 20) cout << a[n] << endl;
  else if (n % 10 == 0) cout << b[n / 10] << endl;
  else {
    int x = n / 10;
    int y = n % 10;
    cout << b[x] << "-" << a[y] << endl;
  }
  return 0;
}