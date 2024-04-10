#include <iostream>

using namespace std;
int n, a[1000];

int main()
{
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];
    for(int i=0;i<n;i++)
        if(a[i]%2==0)
        a[i]--;
    for(int i=0;i<n;i++)
        cout << a[i] << ' ';
    return 0;
}