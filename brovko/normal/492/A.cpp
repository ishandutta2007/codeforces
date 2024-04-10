#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int s = 0, x = 0;

    for(int i = 1; ; i++)
    {
        x += i;
        s += x;

        if(s > n)
        {
            cout << i - 1;
            return 0;
        }
    }


}