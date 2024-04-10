#include <bits/stdc++.h>

typedef long long int ll;
typedef long double ld;

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    string st;
    int n, m;

    cin >> n >> m;

    for (int i = 0; i < n*m; ++i)
    {
        cin >> st;
        if (st == "C" || st == "M" || st == "Y")
        {
            cout << "#Color";
            return 0;
        }
    }

    cout << "#Black&White";

    fclose(stdin);
    fclose(stdout);

    return 0;
}