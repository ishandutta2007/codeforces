#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <algorithm>

using namespace std;

int main(){
  long long a1, a2, a3, a4, a5, a6;
  cin >> a1 >> a2 >> a3 >> a4 >> a5 >> a6;
  cout << (a1+a2+a3) * (a1+a2+a3) - a1*a1-a3*a3-a5*a5;

  return 0;
}