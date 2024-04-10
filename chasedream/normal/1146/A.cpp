#include <bits/stdc++.h>
using namespace std;

string s;

int main() {
  cin>>s;
  int len=s.size(), tot = 0;
  for (int i=0;i<len;i++)
    if (s[i] == 'a') tot++;
  printf("%d\n",min(2*tot-1,len));
  return 0;
}