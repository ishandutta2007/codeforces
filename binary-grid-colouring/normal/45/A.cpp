#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
std::map<int, int> mp;

string s[12]={"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November","December"};
int main(int argc, char const *argv[]) {
  string ss;
  std::cin >> ss;
  int id = 0;
  for(int i=0;i<12;i++) {
    if(ss==s[i]) {
      id = i;
    }
  }
  // std::cout << id << '\n';
  int k;
  std::cin >> k;
  std::cout << s[(id+k)%12] << '\n';
  return 0;
}