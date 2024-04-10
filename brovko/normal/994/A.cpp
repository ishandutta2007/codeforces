#include <iostream>

using namespace std;
int n, m, x[10], y[10], b[10];

int main()
{
    cin >> n >> m;
    for(int i=0;i<n;i++)
        cin >> x[i];
    for(int i=0;i<m;i++)
    {
        cin >> y[i];
        b[y[i]]++;
    }
    for(int i=0;i<n;i++)
        if(b[x[i]]!=0)
        cout << x[i] << ' ';
    return 0;
}