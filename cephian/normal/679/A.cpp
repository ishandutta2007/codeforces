#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <vector>

using namespace std;

int tst[19]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,4,9,25,49};

int main() {
  int ys = 0;
  for(int i = 0; i < 19; ++i) {
    cout << tst[i] << "\n";
    fflush(stdout);
    string res;
    cin >> res;
    ys += res=="yes";
  }
  if(ys <= 1) cout << "prime\n";
  else cout << "composite\n";
  return 0;
}