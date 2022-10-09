#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long n, m;
    cin >> n >> m;
    while(n != 0 && m != 0)
    {
        if(n >= 2 * m)
            n %= 2 * m;
        else if(m >= 2 * n)
            m %= 2 * n;
        else
            break;
    }
    cout << n << " " << m << endl;
}