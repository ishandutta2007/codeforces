#include <bits/stdc++.h>

using namespace std;

long long mas[(int)1e5 + !0];

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int c = 0;
    for (int i = 0; i < n; i++)
        if (s[i] == 'A')
            c++;
        else
            c--;
    if (c > 0)
        cout << "Anton" << endl;
    else if (c < 0)
        cout << "Danik" << endl;
    else
        cout << "Friendship" << endl;
    return 0;
}