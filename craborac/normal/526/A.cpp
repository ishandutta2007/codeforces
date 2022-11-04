#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<iostream>

using namespace std;

char mas[300];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> mas[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (mas[i] == '*')
        {
            for (int j = 1; i + 4 * j < n; j++)
            {
                bool d = 1;
                for (int q = 1; q < 5; q++)
                {
                    if (mas[i+ q * j] == '.')
                    {
                        d = 0;
                    }
                }
                if (d)
                {
                    cout << "yes" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "no" << endl;
    return 0;
}