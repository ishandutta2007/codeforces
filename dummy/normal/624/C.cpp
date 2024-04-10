#include <bits/stdc++.h>

using namespace std;

const int N = 1000;

int n, m;
vector< int > adj[N];
char s[N];

int main() {
  scanf("%d%d", &n, &m);
  while(m--) {
    int u, v;
    scanf("%d%d", &u, &v);
    u--; v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  memset(s, 0, sizeof s);
  int a, b , c;
  a = b = c = 0;
  for(int i = 0; i<n; i++)
    if(adj[i].size()+1 == n) {
      b++;
      s[i] = 'b';
    }
  for(int i = 0; i<n; i++) if(s[i] == 0) {
    a = (int)adj[i].size()+1-b;
    s[i] = 'a';
    for(int j = 0; j<adj[i].size(); j++) if(s[adj[i][j]] != 'b') {
      s[adj[i][j]] = 'a';
    }
    break;
  }

  for(int i = 0; i<n; i++) if(s[i] == 0) {
    c++;
    s[i] = 'c';
    if(adj[i].size() + 1 != n - a) {
      puts("No");
      return 0;
    }
    for(int j = 0; j<adj[i].size(); j++)
      if(s[adj[i][j]] == 'a') {
        puts("No");
        return 0;
      }
  }

  if(a + b + c != n) {
    puts("No");
    return 0;
  }

  for(int i = 0; i<n; i++) if(s[i] == 'a') {
    if(adj[i].size() + 1 != n - c) {
        puts("No");
        return 0;
    }
    for(int j = 0; j<adj[i].size(); j++)
      if(s[adj[i][j]] == 'c') {
        puts("No");
        return 0;
      }
  }
  s[n] = '\0';
  puts("Yes");
  printf("%s\n", s);
  return 0;
}