#include <iostream>
#include <iomanip>

using namespace std;
int n, m, a[1000], b[1000];
double mass;

int main()
{
    cin >> n >> m;
    for(int i=0;i<n;i++)
        cin >> a[i];
    for(int i=0;i<n;i++)
        cin >> b[i];
    mass=m;
    for(int i=0;i<n;i++)
        if(a[i]==1 || b[i]==1)
    {
        cout << -1;
        return 0;
    }
    for(int i=n-1;i>=0;i--)
    {
        mass=(double)mass+mass/(b[(i+1)%n]-1);
        mass=(double)mass+mass/(a[i]-1);
    }
    mass=mass-m;
    cout << setprecision(10) << mass;
    return 0;
}