#include <bits/stdc++.h>

using namespace std;


int _count[301000];
int bef[301000];

bool isGreedible(int c, int extra) {
  bool noExtra = true;
  int largest = bef[c];
  while (c>0) {
    if (largest==0) break;

    if (noExtra && c >= extra && largest <= extra) {
      c-=extra;
      noExtra = false;
      largest = min(largest, bef[c]);
    } else {
      int largestCount = _count[largest];
      if (c/largest >= largestCount) {
        c -= largest*largestCount;
        largest = bef[min(c,largest-1)];
      } else {
        c%=largest;
        largest = bef[c];
      }
    }
  }
  return c==0;
}

int main() {
  ios_base::sync_with_stdio(false);
  int c,n;
  cin >> c>>n;
  vector<int> v(n);
  for (int i = 0 ; i < n ; ++ i ) {
    cin >> v[i];
    _count[v[i]]++;
  }
  for (int i = 1 ; i <= c ; ++i ) {
    if (_count[i]) bef[i]=i;
    else bef[i]=bef[i-1];
  }
  for (int ex = 1; ex<c; ex++) {
    if (!isGreedible(c, ex)) {
      cout << ex << endl;
      return 0;
    }
  }
  
  cout << "Greed is good" <<endl;
  return 0;
}