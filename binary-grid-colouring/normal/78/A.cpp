#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int cal(string s)
{
  int sum=0;
  for(int i=0;i<s.size();i++) {
    if(s[i]=='a' || s[i]=='e'|| s[i]=='i'||s[i]=='o'|| s[i]=='u') {
      sum++;
    }
  }
  return sum;
}
int main(int argc, char const *argv[]) {
  string s1,s2,s3;
  getline(cin,s1);
  getline(cin,s2);
  getline(cin,s3);
  if(cal(s1)==5 && cal(s2)==7 && cal(s3)==5) {
    std::cout << "YES" << '\n';
  }
  else std::cout << "NO" << '\n';
  return 0;
}