#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

string s;
int Min[100005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    int n = s.size();

    Min[n] = n - 1;

    for(int i = n - 1; i >= 0; i--)
        {
            if(s[i] <= s[Min[i + 1]])
                Min[i] = i;
            else Min[i] = Min[i + 1];
        }

    stack <int> st;

    int x = 0;
    while(x < n || !st.empty())
    {
        if(!st.empty() && (x >= n || st.top() <= s[Min[x]]))
        {
            cout << (char)st.top();
            st.pop();
        }
        else
        {
            for(int i = x; i < Min[x]; i++)
                st.push(s[i]);

            cout << (char)s[Min[x]];
            x = Min[x] + 1;
        }
    }
}