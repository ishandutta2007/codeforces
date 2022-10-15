#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int M = (int) 1e9 + 7;

int add(int a, int b) {
  a += b;
  if (a >= M) return a - M;
  if (a < 0) return a + M;
  return a;
}

int mul(int a, int b) {return a * (ll) b % M;}

int pw(int a, int b) {
  int r = 1;
  while (b) {
    if (b & 1) r = mul(r, a);
    a = mul(a, a); b /= 2;
  }
  return r;
}

int dv(int a, int b) {return mul(a, pw(b, M - 2));}

const int N = 100000 + 7;
int n, cnt[N];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);


  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {int x; cin >> x; cnt[x]++;}
  for (int i = 1; i < N; i++) {
    for (int j = 2 * i; j < N; j += i) cnt[i] += cnt[j];
  }
  for (int i = 1; i < N; i++) {
    cnt[i] = add(pw(2, cnt[i]), -1);
  }
  for (int i = N - 1; i >= 1; i--) {
    for (int j = 2 * i; j < N; j += i) cnt[i] = add(cnt[i], -cnt[j]);
  }
  cout << cnt[1] << "\n";
}