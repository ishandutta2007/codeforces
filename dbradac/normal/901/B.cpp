#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl
#define REP(i, n) for (int i=0; i<n; i++)
#define FOR(i, a, b) for (int i=(a); i<(b); i++)
#define _ << " " <<

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

#define double long double

double eps = 1e-9;
void trim(vector <double> &V) {
  for (; !V.empty() && abs(V.back()) < eps; V.pop_back());
}

vector <double> modaj(vector <double> A, vector <double> B) {
  vector <double> R;
  for (int inda = (int) A.size() - 1, pot = (int) A.size() - (int) B.size(); pot >= 0; pot--, inda--) {
    int indb = inda - pot;
    double koef = A[inda] / B[indb];

    REP(i, (int) B.size())
      A[i + pot] -= koef * B[i];
  }

  trim(A);
  return A;
}

int euclid(vector <double> A, vector <double> B) {
  trim(A); trim(B);
  if (A.empty() || B.empty()) return 0;
  if (A.size() < B.size()) swap(A, B);

  vector <double> C = modaj(A, B);
  return euclid(B, C) + 1;
}

vector<double> gen(int deg) {
  vector <double> A;
  REP(i, deg)
    A.push_back(rand() % 3 - 1);
  A.push_back(1);

  return A;
}

int main()
{
  int n;
  scanf("%d", &n);

  for (;;) {
    auto A = gen(n);
    auto B = gen(rand() % n);
    if (euclid(A, B) == n) {
      printf("%d\n", (int) A.size() - 1);
      for (auto it : A) printf("%d ", (int) (round(it)));
      printf("\n");

      printf("%d\n", (int) B.size() - 1);
      for (auto it : B) printf("%d ", (int) (round(it)));
      printf("\n");
      break;
    }
  }

  return 0;
}