#include<bits/stdc++.h>

using namespace std;

int a[300];

int main()
{
    int n;
    cin >> n;
    int r = 0;
    int col = 0;
    for (int i = 0; i < n; i++)
    {
        int t = 0;
        cin >> a[i];
        int b = a[i];
        while (b % 2 == 0)
        {
            b /= 2;
            t++;
        }
        if (t > r)
        {
            r = t;
            col = 1;
        }
        else if (t == r)
            col++;
    }
    cout << (1 << r) << " " << col << endl;
    return 0;
}