#include <iostream>
#include <cmath>

using namespace std;
long long b, k, s;

int main()
{
    cin >> b;
    k=0;
    s=(int)sqrt(b);
    for(int i=1;i<=s;i++)
      if(b%i==0)
      k+=2;
    if(s*s==b)
        k--;
    cout << k;
    return 0;
}