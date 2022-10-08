/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 * Date: 2015.02.02
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

int c[26][26];

void no() {
  puts("Impossible");
  exit(0);
}

void go( string *s, int i, int l, int r ) {
  while (l < r && !s[l][i])
    l++;
  if (r <= l + 1)
    return;
  for (int j = l; j < r; j++)
    if (!s[j][i]) 
      no();
  int j = l;
  while (j < r && s[j][i] == s[l][i])
    j++;
  go(s, i + 1, l, j);
  go(s, i, j, r);
  if (j < r)
    c[s[l][i] - 'a'][s[j][i] - 'a'] = 1;
}

int on, o[26], u[26];

void dfs( int v ) {
  u[v] = 1;
  forn(i, 26)
    if (c[v][i]) {
      if (u[i] == 1)
        no();
      if (!u[i])
        dfs(i);
    }
  u[v] = 2;
  o[on++] = v;
}

int main() {
  int n;
  cin >> n;
  string s[n];
  forn(i,n)
    cin >> s[i];
  go(s, 0, 0, n);
  forn(i, 26)
    if (!u[i])
      dfs(i);
  while (on--)
    putchar('a' + o[on]);
  return 0;
}