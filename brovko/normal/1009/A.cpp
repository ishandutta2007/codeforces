#include <iostream>

using namespace std;
int n, m, a[1000], b[1000], k;

int main()
{
    cin >> n >> m;
    for(int i=0;i<n;i++)
        cin >> a[i];
    for(int i=0;i<m;i++)
        cin >> b[i];
    k=0;
    for(int i=0;i<n;i++)
        if(b[k]>=a[i])
        k++;
    cout << k;
    return 0;
}