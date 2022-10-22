#include <bits/stdc++.h>
using namespace std;;
map<int,bool> vis;
int solve (int cur) {
  int cnt = 0;
  while (!vis[cur]) {
    vis[cur] = 1;
    cnt++;
    cur++;
    while (!(cur%10)) cur /= 10;
  }
  return cnt;
}
int main() {
    int n;
    scanf ("%d",&n);
    printf ("%d\n",solve (n));
}