#include <bits/stdc++.h>

using namespace std;

int mas[(int)3e5 + 10];
int arr[(int)3e5 + 10];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, h;
    cin >> n >> h;
    for (int i = 0; i < n; i++)
    {
        cin >> mas[i];
    }
    int le = 0, ri = n + 1;
    while (ri - le > 1)
    {
        int mi = (le + ri) / 2;
        long long s = 0;
        for (int i = 0; i < mi; i++)
            arr[i] = mas[i];
        sort(arr, arr + mi);
        for (int i = mi - 1; i >= 0; i -= 2)
        {
            s += arr[i];
        }
        if (s <= h)
            le = mi;
        else
            ri = mi;
    }
    cout << le << endl;
    return 0;
}