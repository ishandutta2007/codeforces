#include <iostream>

using namespace std;
int n, a[1000], k;

int main()
{
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];
    for(int i=0;i<n;i++)
        if(a[i]==1)
        k++;
    cout << k << endl;
    for(int i=1;i<n;i++)
        if(a[i]==1)
        cout << a[i-1] << ' ';
    cout << a[n-1];
    return 0;
}