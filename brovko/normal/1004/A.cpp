#include <iostream>

using namespace std;
int n, d, a[100], k;

int main()
{
    cin >> n >> d;
    for(int i=0;i<n;i++)
    cin >> a[i];
    for(int i=0;i<n-1;i++)
        if(a[i+1]-a[i]>2*d)
        k=k+2;
    else if(a[i+1]-a[i]==2*d)
        k++;
    k=k+2;
    cout << k;
    return 0;
}