#include <bits/stdc++.h>
using namespace std;

void ask(int x) { cout << "? " << x << endl; }
void print(int x) { cout << "! " << x << endl; }

int main() {
  int n; cin >> n;
  int l = 1, r = n;
  while (l <= r) {
    int mid = (l + r) >> 1; ask(mid);
    int L, R, Mid; cin >> Mid;
    if (mid != 1) ask(mid-1), cin >> L; else L = 1919810;
    if (mid != n) ask(mid+1), cin >> R; else R = 1919810;
    if (Mid<L && Mid<R) return print(mid), 0;
    if (L < R) r = mid - 1; else l = mid + 1;
  }
}