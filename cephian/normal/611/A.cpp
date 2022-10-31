#include <iostream>
#include <sstream>
#include <set>
#include <algorithm>
#include <cstdio>
#include <map>
#include <cmath>

using namespace std;

int week(int d) {
  int c = 4;
  int a = 0;
  for(int i = 0; i < 366; ++i) {
    if(d == c) ++ a;
    ++c;
     c%=7;
  }
  return a;
}

int month(int d) {
  if(d <= 29) {
    return 12;
  } else if(d == 30) {
    return 11;
  } else if(d == 31) {
    return 7;
  } return 0;
}

int main() {
  ios::sync_with_stdio(0);

  int n;
  cin >> n;
  string a, b;
  cin >> a >> b;
  if(b == "week") {
    --n;
    cout << week(n) << "\n";
  } else {
    cout << month(n) << "\n";
  }

  return 0;
}