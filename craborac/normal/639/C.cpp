#include <bits/stdc++.h>

using namespace std;

int mas[(int)3e5];
long long a[(int)3e5];

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    cin.tie(0);
    int n;
    long long mx;
    cin >> n >> mx;
    n++;
    for (int i = 0; i < (int)3e5; i++)
        mas[i] = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        int t = 1;
        if (a[i] < 0)
        {
            t = -1;
            a[i] *= -1;
        }
        //cout << i << " " << ((t >= 0) ? "+" : "") << t << "   ";
        for (int j = 0; j < 30; j++)
        {
            //cout << (int)((a[i] & (1 << j)) > 0);
            mas[i + j] += t * (int)((a[i] & (1 << j)) > 0);
        }
        //cout << endl;
        a[i] *= t;
    }
    /*
    for (int i = 0; i < 8; i++)
        cout << mas[i];
    cout << endl;
    //*/
    bool d = 0;
    //cout << ((-1) % 2) << endl;
    for (int i = 0; i < 3e5; i++)
    {
        if (mas[i] > 1)
        {
            mas[i + 1] += (mas[i] >> 1);
            mas[i] = (mas[i] & 1);
        }
        else if (mas[i] < 0)
        {
            if (i > (int)2e5 + 40)
            {
                for (int j = 0; j < n; j++)
                    a[j] *= -1;
                for (int j = 0; j <= i; j++)
                    mas[j] *= -1;
                d = 1;
                break;
            }
            if ((mas[i] % 2) == 0)
            {
                mas[i + 1] += mas[i] / 2;
                mas[i] = 0;
            }
            else
            {
                mas[i + 1] -= (1 - mas[i]) / 2;
                mas[i] = 1;
            }
        }
    }
    if (d)
    {
        for (int i = 0; i < 3e5; i++)
        {
            if (mas[i] > 1)
            {
                mas[i + 1] += (mas[i] >> 1);
                mas[i] = (mas[i] & 1);
            }
            else if (mas[i] < 0)
            {
                if (i > (int)2e5 + 40)
                {
                    for (int j = 0; j < n; j++)
                        a[j] *= -1;
                    for (int j = 0; j <= i; j++)
                        mas[j] *= -1;
                    d = 1;
                    break;
                }
                if (mas[i] % 2 == 0)
                {
                    mas[i + 1] += mas[i] / 2;
                    mas[i] = 0;
                }
                else
                {
                    mas[i + 1] -= (1 - mas[i]) / 2;
                    mas[i] = 1;
                }
            }
        }
    }
    /*
    for (int i = 0; i < 8; i++)
        cout << mas[i];
    cout << endl;
    //*/
    int q = -1;
    for (int i = 0; i < (int)3e5; i++)
        if (mas[i] == 1)
            q = i;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (q - i + 1 < 33)
        {
            long long b = 0;
            for (int j = 0; j < 33; j++)
            {
                b += ((long long)mas[i + j] << j);
            }
            if (abs(a[i] - b) <= mx && (i != n - 1 || a[i] - b != 0))
            {
                ans++;
            }
        }
        if (mas[i] != 0)
            break;
    }
    cout << ans << endl;
    return 0;
}