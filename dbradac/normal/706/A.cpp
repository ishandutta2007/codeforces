#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cassert>
#include <vector>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl
typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

double Sq(double x)
{
  return x*x;
}

double Dist(P a, P b)
{
  return sqrt(Sq(a.X - b.X) + Sq(a.Y - b.Y));
}

int main()
{
  P ja;
  cin >> ja.X >> ja.Y;

  int n;
  cin >> n;
  double rje = 1e50;

  for (; n--; ) {
    P pz;
    double v;
    cin >> pz.X >> pz.Y >> v;
    rje = min(rje, Dist(ja, pz) / v);
  }

  printf("%.10lf\n", rje);

	return 0;
}