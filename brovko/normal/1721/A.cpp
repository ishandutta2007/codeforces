#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define f first
#define s second
#define pb push_back

using namespace std;
using li = long long;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        char a, b, c, d;
        cin >> a >> b >> c >> d;

        set <int> st;

        st.insert(a);
        st.insert(b);
        st.insert(c);
        st.insert(d);

        cout << st.size() - 1 << "\n";
    }
}