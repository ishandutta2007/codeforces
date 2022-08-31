#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <set>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <memory.h>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;

int main() {
  long long a, b;
  cin >> a >> b;
  long long ans = 0;
  while (a > 0 && b > 0) {
    if (a > b) {
      ans += a / b;
      a %= b;
    } else {
      ans += b / a;
      b %= a;
    }
  }	
  cout << ans << endl;
  return 0;//yoyoyoyooy
}