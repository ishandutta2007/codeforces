#include <iostream>

using namespace std;
int n, K, a[200000], b[1000003], k;

int main()
{
    cin >> n >> K;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        b[a[i]]++;
    }
    k=0;
    for(int i=0;i<1000003;i++)
        for(int j=0;j<b[i];j++)
        {
            a[k]=i;
            k++;
        }
    k=n;
    for(int i=0;i<n-1;i++)
    if(a[i+1]>a[i] && a[i+1]<=a[i]+K)
    k=k-b[a[i]];
    cout << k;
    return 0;
}