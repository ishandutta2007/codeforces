#include <bits/stdc++.h>
#define int long long
#define ld long double
#define f first
#define s second
#define pb push_back

using namespace std;
const int N = 2e5 + 5;

int p[N];

int rec(int l, int r)
{
    if(l > r)
        return 0;

    int ans = 1;

    while(l <= r)
    {
        ans += rec(l + 1, p[l] - 1);
        l = p[l] + 1;
    }

    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;
        n *= 2;

        string s;
        cin >> s;

        stack <int> st;

        for(int i = 0; i < n; i++)
        {
            if(s[i] == '(')
                st.push(i);
            else
            {
                int j = st.top();
                p[i] = j;
                p[j] = i;
                st.pop();
            }
        }

        cout << rec(0, n - 1) << "\n";
    }
}