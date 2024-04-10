#include <iostream>
#include <cmath>

using namespace std;
long long a, b, x, y, d;
long long gcd(long long p, long long q)
{
    while(p>0&&q>0)
        if(p>q)
        p=p%q;
    else q=q%p;
    return p+q;
}

int main()
{
    cin >> a >> b >> x >> y;
    d=y/gcd(x, y);
    if((double)a/x*y<(double)b)
        cout << (long long)((double)a*y/x/d);
        else cout << b/d;
    return 0;
}