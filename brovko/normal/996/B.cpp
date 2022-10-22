#include <iostream>

using namespace std;
int n, a[100000], Min, k, m;

int main()
{
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];
    Min=a[0];
    for(int i=1;i<n;i++)
        Min=min(Min, a[i]);
    k=Min;
    m=Min%n;
    while(a[m]>k)
    {
        k++;
        m=(m+1)%n;
    }
    m++;
    cout << m;
    return 0;
}