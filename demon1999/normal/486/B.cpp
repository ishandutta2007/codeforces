#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
using namespace std;
long long n, m, a[1000][1000], m1, b[1000][1000];
int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            b[i][j] = 1;
    for(int i = 0; i < n;  i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            if(a[i][j] == 0)
            {
                for(int k = 0; k < m; k++)b[i][k] = 0;
                for(int k = 0; k < n; k++)b[k][j] = 0;
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            m1 = 0;
            if(a[i][j] == 1)
            {
                for(int k = 0; k < m; k++)m1 = max(m1, b[i][k]);
                for(int k = 0; k < n; k++)m1 = max(m1, b[k][j]);
                if(m1 == 0)
                {
                    cout << "NO";
                    return 0;
                }
            }
        }
    }
    cout << "YES" << endl;
    for(int i = 0; i < n; i++)
    {
        for(int  j = 0; j < m; j++)cout << b[i][j] << " ";
        cout << endl;
    }
    return 0;
}