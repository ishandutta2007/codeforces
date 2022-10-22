#include <iostream>

using namespace std;
long long n, g, a[150000], b[150000], Min;
long long gcd(long long i, long long j)
{
    if(i*j==0)
        return i+j;
    if(i<j)
        return gcd(i, j%i);
    return gcd(j, i%j);
}

int main()
{
    cin >> n;
    for(long long i=0;i<n;i++)
        cin >> a[i] >> b[i];
    g=a[0]*b[0];
    for(long long i=1;i<n;i++)
        g=gcd(g, a[i]*b[i]);
    if(g==1)
    {
        cout << -1;
        return 0;
    }
    Min=8e18;
    for(long long i=2;i*i<=a[0];i++)
        if(g%i==0)
            Min=min(Min, i);
    for(long long i=2;i*i<=b[0];i++)
        if(g%i==0)
            Min=min(Min, i);
    if(g%a[0]==0)
        Min=min(Min, a[0]);
    if(g%b[0]==0)
        Min=min(Min, b[0]);
    Min=min(Min, g);
    cout << Min;
    return 0;
}