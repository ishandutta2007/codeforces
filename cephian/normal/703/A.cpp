#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <cmath>
#include <set>

using namespace std;
int a=0,b=0,t;

int main() {
  cin >> t;
  for(int i = 0; i < t; ++i) {
    int c,d;
    cin >> c >> d;
    if(c > d)++a;
    else if(c < d)++b;
  }
  if(a==b) cout << "Friendship is magic!^^\n";
  else if(a <b) cout << "Chris\n";
  else cout << "Mishka\n";
  return 0;
}