#include <iostream>

using namespace std;
int n, m, a[100], s, Max;

int main()
{
    cin >> n >> m;
    for(int i=0;i<n;i++)
        cin >> a[i];
    Max=a[0];
    s=a[0];
    for(int i=1;i<n;i++)
    {
        s+=a[i];
        Max=max(Max, a[i]);
    }
    cout << max(Max, (s+m)/n+((s+m)%n!=0)) << ' ' << Max+m;
}