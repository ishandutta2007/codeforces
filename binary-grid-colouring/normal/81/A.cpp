#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string s;
map<int,int>mp;
int main(int argc, char const *argv[]) {
  std::cin >> s;
 std::vector<char> v;
 for(int i=0;i<(int)s.size();i++) {
   if(v.size()==0 || v.back() != s[i]) {
   v.push_back(s[i]);
  }
  else {
    v.pop_back();
  }
 }
 for(int i=0;i<(int)v.size();i++) {
   std::cout  << v[i];
 }
 std::cout  << '\n';
  return 0;
}