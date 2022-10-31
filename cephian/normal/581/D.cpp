#include <iostream>
#include <algorithm>

using namespace std;

int mx = 0;
int sm = 0;
int x[3], y[3];
string lab = "ABC";

void norm() {
  for(int i = 0; i < 3; ++i)
    if(x[i] > y[i]) swap(x[i], y[i]);
}

void prnt() {
  cout << mx << "\n";
  for(int i = 0; i < mx; ++i) {
    for(int j = 0; j < mx; ++j) {
      if(i < x[0]) cout << lab[0];
      else if(j < y[1]) cout << lab[1];
      else cout << lab[2];
    }
    cout << "\n";
  }
}

bool mayb() {
  if(y[1] + y[2] == mx && x[1] == x[2] && x[1] + x[0] == mx) {
    prnt();
    return 1;
  }
  return 0;
}

bool test() {
  norm();
  if(y[0] != mx) return 0;
  if(mayb()) return 1;
  swap(x[1], y[1]);
  if(mayb()) return 1;
  swap(x[2], y[2]);
  if(mayb()) return 1;
  swap(x[1], y[1]);
  if(mayb()) return 1;
  return 0;
}

int main() {
  for(int i = 0; i < 3; ++i) {
    cin >> x[i] >> y[i];
    sm += x[i]*y[i];
    if(x[i] > y[i]) swap(x[i], y[i]);
    mx = max(mx, y[i]);
  }
  if(mx * mx != sm) {
    cout << "-1\n";
    return 0;
  }
  if(x[0]+x[1]+x[2] == mx && y[0] == mx && y[1] == mx && y[2] == mx) {
    cout << mx << "\n";
    for(int i = 0; i < mx; ++i) {
      for(int j = 0; j < mx; ++j) {
        if(i < x[0]) cout << "A";
        else if(i < x[0]+x[1]) cout << "B";
        else cout << "C";
      }
      cout << "\n";
    }
    return 0;
  }
  if(test()) return 0;
  swap(x[0], x[1]);
  swap(y[0], y[1]);
  swap(lab[0], lab[1]);
  if(test()) return 0;
  swap(x[0], x[2]);
  swap(y[0], y[2]);
  swap(lab[0], lab[2]);
  if(test()) return 0;
  cout << "-1\n";
  return 0;
}