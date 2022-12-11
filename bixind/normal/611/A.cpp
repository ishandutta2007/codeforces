#include <iostream>

using namespace std;

int main()
{
    int x;
    string s;
    cin >> x;
    cin >> s;
    cin >> s;
    if (s == "month")
    {
        int ans = 0;
        if (x <= 29)
            ans += 1;
        if (x <= 30)
            ans += 4;
        if (x <= 31)
            ans += 7;
        cout << ans;
    }
    if (s == "week")
    {
        x = (x - 5 + 7) % 7 + 1;
        int ans = 0;
        while (x <= 366)
            ans++, x += 7;
        cout << ans;
    }
    cout << endl;
    return 0;
}