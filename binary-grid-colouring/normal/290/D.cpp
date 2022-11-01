#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e6+3;
const ll INF =2e15;

int main()
{
  string s;int n;
  cin >> s >> n;
  for (int i = 0 ; i < s.size() ; i++) {
      s[i] = tolower(s[i]);
  }
  for (int i = 0 ; i < s.size() ; i++) {
    if (islower(s[i]) && s[i] < 'a' + n)
      putchar(toupper(s[i]));
    else putchar(s[i]);
  }  
  return 0;
}