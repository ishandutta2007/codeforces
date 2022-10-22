#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew

using namespace std;

int n, x, k, a[400005];
string s, t[400005];
priority_queue <int> q;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> s;

        if(s == "insert")
        {
            cin >> x;
            q.push(-x);

            t[k] = s;
            a[k] = x;

            k++;
        }

        if(s == "getMin")
        {
            cin >> x;

            while(!q.empty() && q.top() > -x)
                {
                    q.pop();

                    t[k] = "removeMin";
                    k++;
                }

            if(q.empty() || q.top() != -x)
            {
                q.push(-x);

                t[k] = "insert";
                a[k] = x;

                k++;
            }

            t[k] = "getMin";
            a[k] = x;

            k++;
        }

        if(s == "removeMin")
        {
            if(q.empty())
            {
                q.push(0);
                t[k] = "insert";
                a[k] = 0;

                k++;
            }

            q.pop();

            t[k] = s;
            k++;
        }
    }

    cout << k << "\n";

    for(int i = 0; i < k; i++)
    {
        cout << t[i] << ' ';

        if(t[i] != "removeMin")
            cout << a[i];

        cout << "\n";
    }
}