#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX = 200010;

int n;
int p[MAX];
double pref[MAX];

double Eval(double x)
{
  double maxx = 0, minn = 0;
  double ret = 0;

  for (int i=1; i<=n; i++) {
    pref[i] = pref[i-1] + p[i] - x;
    maxx = max(maxx, pref[i]);
    minn = min(minn, pref[i]);
    ret = max(ret, max(abs(pref[i] - maxx), abs(pref[i] - minn)));
  }

  return ret;
}

int main()
{
  scanf("%d", &n);

  for (int i=1; i<=n; i++)
    scanf("%d", &p[i]);

  double tmp=0, pom=10000; 

  for (int i=0; i<200; i++) {
    double mid = Eval(tmp);
    double lo = Eval(tmp - pom);
    double hi = Eval(tmp + pom);

    if (lo > mid && hi > mid)
      pom /= 2;
    if (lo < mid)
      tmp -= pom;
    else if (hi < mid)
      tmp += pom;
  }

  printf("%.14lf\n", Eval(tmp));

  return 0;
}