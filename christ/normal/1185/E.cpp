#include <bits/stdc++.h>
using namespace std;
char mp[3001][3001];
bool contains[26];
int leftmost[26],rightmost[26],upmost[26],downmost[26];
int main() {
  int t;
  scanf ("%d",&t);
  while (t--) {
    int n,m,last=-1;
    scanf ("%d %d",&n,&m);
    memset(contains,0,sizeof contains); memset(leftmost,0x3f,sizeof leftmost); memset(upmost,0x3f,sizeof upmost); memset(rightmost,0,sizeof rightmost); memset(downmost,0,sizeof downmost);
    for (int x = 0; x < n; x++) {
      scanf ("%s",mp[x]);
      for (int y = 0; y < m; y++) if (mp[x][y] != '.') {
        int ind = mp[x][y]-'a';
        last = max(last,ind);
        contains[ind] = 1;
        leftmost[ind] = min(leftmost[ind],x);
        rightmost[ind] = max(rightmost[ind],x);
        upmost[ind] = min(upmost[ind],y);
        downmost[ind] = max(downmost[ind],y);
      }
    }
    for (int x = 0; x <= last; x++) {
      if (!contains[x]) continue;
      if (leftmost[x] != rightmost[x] && upmost[x] != downmost[x]) {printf ("NO\n"); goto out;}
      if (leftmost[x] == rightmost[x]) {
        for (int y = upmost[x]; y <= downmost[x]; y++) if (mp[leftmost[x]][y] == '.' || (mp[leftmost[x]][y]-'a')<x) {printf ("NO\n"); goto out;}
      }
      else {
        for (int xx = leftmost[x]; xx <= rightmost[x]; xx++) if (mp[xx][upmost[x]] == '.' || (mp[xx][upmost[x]]-'a')<x) {printf ("NO\n"); goto out;}
      }
    }
    printf ("YES\n%d\n",last+1);
    for (int x = 0; x <= last; x++) {
      if (!contains[x])printf ("%d %d %d %d\n",leftmost[last]+1,upmost[last]+1,rightmost[last]+1,downmost[last]+1);
      else printf ("%d %d %d %d\n",leftmost[x]+1,upmost[x]+1,rightmost[x]+1,downmost[x]+1);
    }
    out:;
  }
  return 0;
}