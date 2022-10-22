#include <iostream>

using namespace std;
int n, a[100], Max, x, s;

int main()
{
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];
    Max=a[0];
    for(int i=0;i<n;i++)
        Max=max(Max, a[i]);
    s=0;
    for(int i=0;i<n;i++)
        s+=a[i];
    s=s*2;
    x=Max;
    while(x*n<=s)
        x++;
    cout << x;
    return 0;
}