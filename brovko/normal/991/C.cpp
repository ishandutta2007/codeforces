#include <iostream>

using namespace std;
long long n, k, p, v, m, l, r, M;

int main()
{
    cin >> n;
    m=n;
    l=0;
    r=n+1;
    while(r-l>1)
    {
        M=(l+r)/2;
        k=M;
        p=0;
        v=0;
        while(n>0)
        {
            v=v+min(n, k);
            n=n-min(n, k);
            p=p+n/10;
            n=n-n/10;
        }
        n=m;
        if(p>v)
            l=M;
        else r=M;
    }
    cout << r;
    return 0;
}