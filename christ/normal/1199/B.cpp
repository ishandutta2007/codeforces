#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
  ll h,l;
  scanf ("%lld %lld",&h,&l);
  printf ("%.9f\n",(l * l - h * h) / double(2*h));
  return 0;
}