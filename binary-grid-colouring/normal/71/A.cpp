#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


string s[123],ss[123];
int main(int argc, char const *argv[]) {

 int n;
 std::cin >> n;
 for(int i=0;i<n;i++) {
   std::cin >> s[i];
   if(s[i].size() <= 10) {
     std::cout << s[i] << '\n';
   }
   else {
     std::cout << s[i][0] << s[i].size()-2 << s[i][s[i].size()-1] << '\n';
   }
 }

  return 0;
}