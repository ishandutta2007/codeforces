#include <iostream>

using namespace std;
int n, a[100], s;

int main()
{
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];
    s=0;
    for(int i=1;i<n;i++)
        s=s+4*a[i]*i;
    cout << s;
    return 0;
}