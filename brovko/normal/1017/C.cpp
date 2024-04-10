#include <iostream>

using namespace std;
int n, k, m;

int main()
{
    cin >> n;
    k=1;
    while(k*k<=n)
        k++;
    k--;
    for(int i=n/k*k+1;i<=n;i++)
        cout << i << ' ';
    n=n/k*k;
    while(n>0)
    {
        n=n-k;
        for(int i=n+1;i<=n+k;i++)
            cout << i << ' ';
    }
    return 0;
}