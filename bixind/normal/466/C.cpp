#include <iostream>

using namespace std;

int main()
{
    int n, i;
    cin >> n;
    long long m[n], sum;
    int fc[n], rc[n];
    cin >> m[0];
    sum = m[0];
    for (i = 1; i < n; i++)
    {
        cin >> m[i];
        sum = m[i] + sum;
    }
    if (sum % 3 != 0 || n < 3)
    {
        cout << 0;
        return 0;
    }
    long long d;
    d = sum / 3;
    long long k = 0;
    sum = m[n - 1];
    if (sum == d) {
        k++;
        rc[n - 1] = k;
    }
    else
    {
        rc[n - 1] = k;
    }
    //cout << rc[n - 1] << endl;
    for (i = n - 2; i >= 0; i--)
    {
        sum = sum + m[i];
        if (sum == d) {
            k++;
            rc[i] = k;
        } else {
            rc[i] = k;
        }
        //cout << rc[i] << endl;
    }
    k = 0;
    sum = m[0];
    if (sum == d) {
        k++;
        fc[0] = k;
    }
    else
    {
        fc[0] = k;
    }
    for (i = 1; i < n; i++)
    {
        sum = sum + m[i];
        if (sum == d) {
            k++;
            fc[i] = k;
        } else {
            fc[i] = k;
        }
    }
    k = 0;
    sum = 0;
    for (i = 0; i < n - 2; i++)
    {
        sum += m[i];
        if (sum == d)
            k += rc[i + 2];
    }
    cout << k;
    return 0;
}