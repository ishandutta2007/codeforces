#include <bits/stdc++.h>
#define li long long

using namespace std;



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        for(int i = n + 1; i <= 2 * n; i++)
            cout << i << ' ';

        cout << "\n";
    }
}