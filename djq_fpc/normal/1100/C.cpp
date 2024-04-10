#include <bits/stdc++.h>
using namespace std;

const double PI=acos(-1);

int __cdecl main(int argc, const char **argv, const char **envp)
{
  long double v3; // fst7@1
  double v4; // ST10_8@1
  long double v5; // fst7@1
  double v7; // [sp+28h] [bp-18h]@1
  signed int v8; // [sp+34h] [bp-Ch]@1
  double v9; // [sp+38h] [bp-8h]@1

  scanf("%d%lf", &v8, &v7);
  v9 = (long double)(v8 - 2) * *(double *)&PI / (long double)v8 / 2.0;
  v3 = cos(v9);
  v4 = v3 * v7;
  v5 = cos(v9);
  printf("%.7lf\n", (double)(v4 / (1.0 - v5)));
  return 0;
}