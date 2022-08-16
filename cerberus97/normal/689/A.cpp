#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int n;
    char s[10];
    bool used[10] = {false};

    cin >> n >> s;

    for (int i = 0; i < n; ++i)
    {
        used[s[i] - '0'] = true;
    }

    bool ans = true;

    if (used[0])
    {
        if (!used[1] and !used[2] and !used[3])
            ans = false;
    }

    else if (!used[7] and !used[9])
        ans = false;

    else if (!used[1] and !used[4] and !used[7])
        ans = false;

    else if (!used[3] and !used[6] and !used[9])
        ans = false;

    else if (!used[1] and !used[2] and !used[3])
        ans = false;

    if (ans)
        cout << "YES";

    else
        cout << "NO";

    return 0;
}