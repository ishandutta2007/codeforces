#include <iostream>

using namespace std;
int n, k, a[100], m1, m2, i;

int main()
{
    cin >> n >> k;
    for(i=0;i<n;i++)
        cin >> a[i];
    i=0;
    while(i<n && a[i]<=k)
        i++;
    m1=i;
    i=n-1;
    while(i>=0 && a[i]<=k)
        i--;
    m2=i;
    if(m1==n)
        cout << n;
    else
        cout << m1+n-m2-1;
    return 0;
}