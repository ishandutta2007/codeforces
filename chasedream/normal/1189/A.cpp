// luogu-judger-enable-o2
%:pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;

string str;
int n, cnt = 0;

int main() {
  scanf("%d", &n);
  cin >> str;
  for (int i = 0; i < n; i++)
    if (str[i] == '0') cnt++;
    else cnt--;
  
  if (cnt == 0) {
    puts("2");
    cout << str.substr(0, n - 1) << ' ' << str[n - 1] << '\n';
  }
  else {
    puts("1");
    cout << str << '\n';
  }
  return 0;
}