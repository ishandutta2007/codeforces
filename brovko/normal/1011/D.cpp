#include <iostream>

using namespace std;
int m, n, l, r, x, f, a[30];

int main()
{
    cin >> m >> n;
    for(int i=0;i<n;i++)
    {
        cout << i+1 << endl << flush;
        cin >> f;
        if(f==0)
            return 0;
        a[i]=f;
    }
    int i=0;
    l=n-1;
    r=m+1;
    while(r-l>1)
    {
        x=(l+r)/2;
        cout << x << endl << flush;
        cin >> f;
        if(f==0)
            return 0;
        if(f==a[i])
            l=x;
        else r=x;
        i=(i+1)%n;
    }
    cout << l << endl << flush;
    return 0;
}