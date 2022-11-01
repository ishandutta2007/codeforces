#include <bits/stdc++.h>

using namespace std;

long long n;

int main() {
  cin >> n;
  n++;
  long long l, r;
  l = 0; r = 1e9;
  while(l < r) {
    long long mid = (l+r+1)>>1;
    long long now = 1LL + 3LL*mid*(mid+1);
    if(now > n)
      r = mid - 1;
    else
      l = mid;
  }
  n -= 1LL + 3*l*(l+1);
  long long x = 2*l, y = 0;
  if(n == 0) {
    cout << x << ' ' << y << endl;
    return 0;
  }
  n--;
  l++;
  x++;
  y += 2;
  if(n <= l-1) {
     x -= n;
     y += 2*n;
    cout << x << " " << y << endl;
    return 0;
  }
  else {
    x -= l-1;
    y += 2*(l-1);
  }
  n -= l-1;
  if(n <= l) {
    x -= 2*n;
    cout << x << " " << y << endl;
    return 0;
  }
  else
    x -= 2*l;
  n -= l;
  if(n <= l) {
    x -= n;
    y -= 2*n;
    cout << x << " " << y << endl;
    return 0;
  }
  else {
    x -= l;
    y -= 2*l;
  }
  n -= l;
  if(n <= l) {
    x += n;
    y -= 2*n;
    cout << x << " " << y << endl;
    return 0;
  }
  else {
    x += l;
    y -= 2*l;
  }
  n -= l;
  if(n <= l) {
    x += 2*n;
    cout << x << " " << y << endl;
    return 0;
  }
  else {
    x += 2*l;
  }
  n -= l;
  x += n;
  y += 2*n;
  cout << x << " " << y << endl;

  return 0;
}