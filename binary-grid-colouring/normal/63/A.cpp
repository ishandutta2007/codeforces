#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


string s[123],ss[123];
int main(int argc, char const *argv[]) {

  int n;

  std::cin >> n;
  for(int i=0;i<n;i++) {
    std::cin >> s[i] >> ss[i];
  }
  for(int i=0;i<n;i++) {
    if(ss[i]=="rat") {
      std::cout << s[i] << '\n';
    }
  }
  for(int i=0;i<n;i++) {
    if(ss[i]=="woman" || ss[i]=="child") {
      std::cout << s[i] << '\n';
    }
  }
  for(int i=0;i<n;i++) {
    if(ss[i]=="man") {
      std::cout << s[i] << '\n';
    }
  }
  for(int i=0;i<n;i++) {
    if(ss[i]=="captain") {
      std::cout << s[i] << '\n';
    }
  }
  return 0;
}