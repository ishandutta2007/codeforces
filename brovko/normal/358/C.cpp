#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, a[100005], used[100005];
priority_queue <pair <int, int> > q;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];

        if(a[i] == 0)
        {
            int N = min(3, (int)q.size());

            for(int j = 0; j < N; j++)
            {
                used[q.top().y] = 1;
                q.pop();
            }

            while(q.size())
                q.pop();
        }
        else q.push({a[i], i});
    }

    int S = 0, Q = 0, D = 0, x = 0;

    for(int i = 0; i < n; i++)
    {
        if(used[i])
        {
            if(x % 3 == 0)
            {
                cout << "pushStack\n";
                S++;
            }
            else if(x % 3 == 1)
            {
                cout << "pushQueue\n";
                Q++;
            }
            else
            {
                cout << "pushFront\n";
                D++;
            }

            x++;
        }
        else if(a[i])
        {
            cout << "pushBack\n";
        }
        else
        {
            int k = (bool)S + (bool)Q + (bool)D;

            cout << k;

            if(k)
                cout << ' ';

            string s;

            if(S)
            {
                s += "popStack ";
                S--;
            }

            if(Q)
            {
                s += "popQueue ";
                Q--;
            }

            if(D)
            {
                s += "popFront ";
                D--;
            }

            if(s.size() && s.back() == ' ')
                s = s.substr(0, (int)s.size() - 1);

            cout << s;

            cout << "\n";
        }
    }
}