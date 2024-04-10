#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, t;
  cin >> n >> t;
  if(n == 1 && t == 10)
    puts("-1");
  else {
    if(t == 10) {
      for(int i = 1; i<n; i++) printf("1");
      printf("0\n");
    }
    else {
      for(int i = 0; i<n; i++) printf("%d", t);
      printf("\n");
    }
  }
    
    


  return 0;
}