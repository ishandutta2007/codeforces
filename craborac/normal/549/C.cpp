#include<cstdio>
#include<cmath>
#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int a = 0, b = 0;
    for (int i = 0; i < n; i++)
    {
        int c;
        cin >> c;
        if (c % 2 == 0)
        {
            a++;
        }
        else
        {
            b++;
        }
    }
    if (n == k)
    {
        if (b % 2 == 0)
        {
            cout << "Daenerys" << endl;
        }
        else
        {
            cout << "Stannis" << endl;
        }
        return 0;
    }
    if ((n - k) % 2 == 0)
    {
        if (b <= (n - k) / 2 || a > (n - k) / 2)
        {
            cout << "Daenerys" << endl;
        }
        else
        {
            b = b - (n - k) + a;
            if (b % 2 == 0)
            {
                cout << "Daenerys" << endl;
            }
            else
            {
                cout << "Stannis" << endl;
            }
        }
    }
    else
    {
        if (b <= (n - k) / 2)
        {
            cout << "Daenerys" << endl;
        }
        else if (a > (n - k) / 2)
        {
            cout << "Stannis" << endl;
        }
        else
        {
            b = b - (n - k) + a;
            if (b % 2 == 0)
            {
                cout << "Daenerys" << endl;
            }
            else
            {
                cout << "Stannis" << endl;
            }
        }
    }
    return 0;
}