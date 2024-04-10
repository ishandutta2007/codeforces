#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i", &n);
    int prev = 0, ans = 0;
    string s;
    for (int x = 0; x < n; x++)
    {
        char c;
        scanf(" %c", &c);
        s += c;
    }
    s += s;
    for (int x = 0; x < s.length(); x++)
    {
        if (s[x] == '1')
            prev++;
        else
            ans = max(ans, prev), prev = 0;
    }
    ans = max(ans, prev);
    cout<<ans<<"\n";
}