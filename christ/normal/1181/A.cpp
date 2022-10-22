#include <bits/stdc++.h>
using namespace std;
int main() {
    long long a,b,c;
    scanf ("%lld %lld %lld",&a,&b,&c);
    long long total = (a+b)/c;
    if (total == 0) return !printf ("0 0\n");
    else if (total == 1) return !printf("1 %lld\n",min(abs(a-c),abs(b-c)));
    else {
      long long possibleMod = (a+b)%c, curMod = a%c+b%c;
      if (curMod <= possibleMod) return !printf ("%lld 0\n",total);
      long long aaa = min(a%c,min(c-a%c,min(b%c,c-b%c)));
      if (aaa == a%c) {
        if (((a-aaa) + (b+aaa))/c == total)return !printf ("%lld %lld\n",total,min(aaa,min(a,b)));
        else return !printf ("%lld %lld\n",total,min(a,b));
      }
      else if (aaa == c-a%c) {
        if (((a+aaa)+(b-aaa))/c == total) return !printf ("%lld %lld\n",total,min(aaa,min(a,b)));
        else return !printf ("%lld %lld\n",total,min(a,b));
      }
      else if (aaa == b%c) {
        if (((a+aaa)+(b-aaa))/c == total) return !printf ("%lld %lld\n",total,min(aaa,min(a,b)));
        else return !printf ("%lld %lld\n",total,min(a,b));
      }
      else {
        if (((a-aaa)+(b+aaa))/c == total) return !printf ("%lld %lld\n",total,min(aaa,min(a,b)));
        else return !printf ("%lld %lld\n",total,min(a,b));
      }
    }
    return 0;
}