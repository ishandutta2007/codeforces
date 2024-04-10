#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i", &n);
    string s;
    cin>>s;
    set<char> cur;
    int ans = INT_MIN;
    for (int x = 0; x < n; x++)
    {
        if (isupper(s[x]))
        {
            ans = max(ans, (int)cur.size());
            cur.clear();
        }
        else
            cur.insert(s[x]);
    }
    ans = max(ans, (int)cur.size());
    printf("%i\n", ans);
}