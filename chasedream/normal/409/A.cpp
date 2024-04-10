%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128

string a, b;
int m = 0, k = 0;

int main() {
  getline(cin, a); getline(cin, b);
  int len = a.size();
  for (int i = 1; i < len; i += 2) {
    if (a[i] == '<') {
      if (b[i] == '<') ;
      else if (b[i] == ']') m++;
      else k++;
    }
    else if (a[i] == ')') {
      if (b[i] == '<') m++;
      else if (b[i] == ']') k++;
      else ;
    }
    else {
      if (b[i] == '<') k++;
      else if (b[i] == ']') ;
      else m++;
    }
  }
  
  if (m == k) puts("TIE");
  else puts(m > k ? "TEAM 1 WINS" : "TEAM 2 WINS");
  return 0;
}