#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e6+3;
const ll INF =2e15;
int a,b,c,d,e,f;
ll res;
bool calc(long long x)
{
  long long Last=x;
  if(d>0&&c==0) return true;
  if(a==0&&b>0&&d!=0) return true;
  if(d==0) return false;

  if((a==0)&&b) x=INF;
  else if(b==0) x=0;
  else x=x/a*b;

  if ((c==0)&&d) x=INF;
  else if (d==0) x=0;
  else {
    x=x/c*d;
    if (x>INF) x=INF;
  }
  if (x==0) return false;

  if ((e==0)&&f) x=INF;
  else if (e==0) x=0;
  else x=x/e*f;

  if(x>Last) return true;
  else return false;
}
int main(int argc, char const *argv[]) {

  std::cin >> a >> b >> c >> d >> e >> f;
  if(a==0 && b==0 && c==0 && d==0 && f==0 && e==0) {
    std::cout << "Hermione" << '\n';
    return 0;
  }
  if(a==0 || c==0 || e==0) {
    if(calc(100000000)) {
      std::cout << "Ron" << '\n';return 0;
    }
    else
    {
      std::cout << "Hermione" << '\n';return 0;
    }
  }
  else if(calc(1LL*a*c*e)) {
    std::cout << "Ron" << '\n';return 0;
  }
  else std::cout << "Hermione" << '\n';
  return 0;
}