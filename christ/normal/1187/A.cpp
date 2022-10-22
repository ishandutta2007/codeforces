#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  scanf ("%d",&T);
  while (T--) {
    int n,s,t;
    scanf ("%d %d %d",&n,&s,&t);
    if (s == n && t == n) {
      printf ("1\n");
    }
    else if (s+t>n) {
      n -= min(s,t);
      printf ("%d\n",min(max(s,t),n)+1);
      //printf ("%d\n",min(n*2-(s+t),min(max(s,t),n/2))+1);
    } 
    else {
      printf ("%d\n",max(s,t)+1);
    }
  }
  return 0;
}