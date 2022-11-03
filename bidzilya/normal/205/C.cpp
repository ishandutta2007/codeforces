#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

typedef long long lli;
lli b[20];

lli ans(lli v)
{
    if (v<10)
       return v;
    int lv = 0;
    lli fz = v, lz = v%10, mid = v, res = 9;
    while (fz>9)
    {
          lv++;
          fz/=10;
    }
    mid = v-fz*b[lv]-lz;
    mid /= 10;
    lv++;
    
    for (int cif = 1;cif<10;cif++)
        for (int len=0;len<=lv-2;len++)
        {
            if (len<lv-2 || (len==lv-2 && cif<fz))
               res += b[len];
            else
            if (len==lv-2 && cif==fz)
               res += mid;
            if (len==lv-2 && cif==fz && lz>=cif)
               res++;
        }
    return res;
}

int main()
{
    b[0]=1;
    for (int i=1;i<20;i++) b[i] = b[i-1]*10;
    
    lli l,r;
    cin >> l >> r;
    cout << ans(r)-ans(l-1);
    return 0;
}