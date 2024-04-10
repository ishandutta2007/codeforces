#include <iostream>
#include <algorithm>

using namespace std;

int tens = 0;
int rem[100005];

int main() {
  int n, k;
  cin >> n >> k;
  int q = 0;
  int rat = 0;
  for(int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    rat += a/10;
    int r = (200-a)%10;
    if(r != 0) rem[q++] = r;
    tens += (100-(a+r))/10;
  }
  sort(rem, rem+q);
  for(int i = 0; i < q; ++i) {
     if(rem[i] > k) break;
     k -= rem[i];
     ++rat;
  }
  rat += min(tens, k/10);
  cout << rat << "\n";
}