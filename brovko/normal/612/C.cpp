#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back
#define mp make_pair

using namespace std;

string s;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s;

    stack <char> q;
    int ans = 0;

    for(auto to:s)
    {
        if(to == '{' || to == '<' || to == '(' || to == '[')
            q.push(to);

        else if(q.empty())
        {
            cout << "Impossible";
            return 0;
        }

        else if(to == '}' && q.top() == '{' || to == ')' && q.top() == '(' || to == ']' && q.top() == '[' || to == '>' && q.top() == '<')
            q.pop();

        else
        {
            ans++;
            q.pop();
        }
    }

    if(!q.empty())
    {
        cout << "Impossible";
        return 0;
    }

    cout << ans;
}