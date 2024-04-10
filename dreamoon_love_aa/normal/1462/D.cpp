#include <iostream>
#include <set>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[3100];
    int sum = 0;
    for(int i = 1; i <= n; i++){
      cin >> a[i];
      sum += a[i];
    }
    for(int i = 1; i <= n; i++){
      int now = 0;
      int need = 0;
      bool fail = 0;
      int seg_num = 1;
      for(int j = 1; j <= n; j++) {
        now += a[j];
        if(j == i) {
          need = now;
          now = 0;
        } else if(j > i) {
          if(now > need) {
            fail = 1;
          } else if(now == need) {
            now = 0;
            seg_num++;
          } 
        }
      }
      if(now) { fail = 1;}
      if(!fail) {
        printf("%d\n", n - seg_num);
        break;
      }
    }
  }
  return 0;
}