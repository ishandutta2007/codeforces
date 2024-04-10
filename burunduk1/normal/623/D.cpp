/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

const int N = 100;

typedef double dbl;

int n, k[N];
dbl p[N], p_log[N], p_log_1[N];
priority_queue<pair<dbl, int>> s;

inline dbl P( int i, int k ) {
  dbl x = pow(p[i], k);
  if (x > 1e-6)
    return log(1 - x);
  x = -x;
  return x - x * x / 2 + x * x * x / 3;
}

void add( int i ) {
  //printf("%d, %d : %.15f\n", i, k[i], (double)(P(i, k[i] + 1) - P(i, k[i])));
  s.push(make_pair(P(i, k[i] + 1) - P(i, k[i]), i));
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  if (n == 1) {
    puts("1");
    return 0;
  }
  forn(i, n) {
    int a;
    cin >> a;
    p[i] = 1 - a * 1e-2;
    p_log[i] = log(p[i]);
    p_log_1[i] = log(1 - p[i]);
  }
  dbl sum = 0;
  int cnt = n;
  forn(i, n)
    sum += P(i, k[i] = 1);
  dbl res = exp(sum) * cnt;
  forn(i, n)
    add(i);
  //printf("%.15f\n", (double)res);
  while (cnt <= 1e6) {
    //if (!(cnt & (cnt - 1)))
    //  printf("%9d : %.15f\n", cnt, (double)res);
    cnt++;
    int i = s.top().second; s.pop();
    sum -= P(i, k[i]);
    dbl x = cnt * exp(sum + p_log[i] * k[i]) * (1 - p[i]);// + p_log_1[i];
    res += x;
    //if (res > 0.5 && x < 1e-8)
    //  break;
    //printf("i=%d, k=%d: + %d * %.15f\n", i, k[i], cnt , (double)(exp(sum + log(p[i]) * k[i]) * (1 - p[i])));
    sum += P(i, ++k[i]);
    add(i);
  }
  printf("%.15f\n", (double)res);
  fprintf(stderr, "time = %.2f, cnt = %d\n", 1. * clock() / CLOCKS_PER_SEC, cnt); // stamp
  return 0;
}