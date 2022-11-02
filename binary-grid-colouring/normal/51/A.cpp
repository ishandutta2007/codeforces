#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

std::map<string, int> mp;
int main(int argc, char const *argv[]) {
  int n;
  std::cin >> n;
  for(int i=0;i<n;i++)
   {
     string cur;
     char c;
     for(int j=0;j<4;j++) {
       std::cin >> c;
       cur.push_back(c-'0');
     }
     swap(cur[2],cur[3]);
     if(i < n - 1) {
       std::cin >> c >> c;
     }
     string s = cur.substr(1) + cur.substr(0,1);
     string ss = cur.substr(2) + cur.substr(0,2);
     string sss = cur.substr(3) + cur.substr(0,3);
     cur = min(cur,s);
     cur = min(cur,ss);
     cur = min(cur,sss);
     mp[cur]++;
   }
   std::cout << (int)mp.size() << '\n';
  return 0;
}