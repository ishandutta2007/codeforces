#include <iostream>

using namespace std;
long long n, m, k, l;
long long kr(long long x, long long y)
{
    if(x%y==0)
        return x/y;
    else return x/y+1;
}

int main()
{
    cin >> n >> m >> k >> l;
    if(n<m || kr(k+l, m)*m>n)
        cout << -1;
    else cout <<  kr(k+l, m);
    return 0;
}