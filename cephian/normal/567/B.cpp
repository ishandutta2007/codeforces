#include <iostream>
#include <sstream>
#include <set>
#include <algorithm>
#include <cstdio>
#include <map>
#include <cmath>

using namespace std;

bool in[1000005]={0};

int main() {
  ios::sync_with_stdio(0);
  int n;
  cin >> n;
  int ans = 0;
  int room = 0;
  for(int i = 0; i < n; ++i) {
    string t;
    int id;
    cin >> t >> id;
    if(t == "+") {
      ++room;
      in[id]=1;
    } else {
      if(!in[id])
        ++ans;
      else
        --room;
    }
    ans = max(ans, room);
  }
  cout << ans << "\n";
  return 0;
}