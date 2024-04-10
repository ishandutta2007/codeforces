#include <iostream>

using namespace std;
int n, m, a[100][100], Min[100], Max;

int main()
{
    cin >> n >> m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        cin >> a[i][j];
    for(int i=0;i<100;i++)
        Min[i]=1000000000;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        Min[i]=min(Min[i], a[i][j]);
    for(int i=0;i<n;i++)
        Max=max(Max, Min[i]);
    cout << Max;
    return 0;
}