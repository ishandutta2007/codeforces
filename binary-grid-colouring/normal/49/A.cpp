#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(int argc, char const *argv[]) {
  string s;char ans;
  getline(cin,s);
  for(int i=0;i<s.size();i++) {
    if(s[i] >='A' && s[i]<='z') {
       ans = s[i];
    }
  }
  if(ans=='a'||ans=='e' || ans=='i' || ans =='o' || ans == 'u'|| ans=='y')
  {
    std::cout << "YES" << '\n';
  }
  else if(ans=='A'||ans=='E' || ans=='I' || ans =='O' || ans == 'U'|| ans=='Y') {
    std::cout << "YES" << '\n';
    return 0;
  }
  else std::cout << "NO" << '\n';
  return 0;
}