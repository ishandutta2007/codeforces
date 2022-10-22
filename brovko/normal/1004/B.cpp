#include <iostream>

using namespace std;
int n, m, a[1000], b[1000], c[1000];


int main()
{
    cin >> n >> m;
    for(int i=0;i<m;i++)
        cin >> a[i] >> b[i];
    c[0]=0;
    for(int i=1;i<n;i++)
        c[i]=1-c[i-1];
    for(int i=0;i<n;i++)
        cout << c[i];
    return 0;
}