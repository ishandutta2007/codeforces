#include <iostream>

using namespace std;
int n, a[100], b[101], Max;

int main()
{
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];
    for(int i=0;i<n;i++)
        b[a[i]]++;
    Max=0;
    for(int i=1;i<101;i++)
        Max=max(Max, b[i]);
    cout << Max;
    return 0;
}