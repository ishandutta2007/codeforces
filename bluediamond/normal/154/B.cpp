#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e5 + 7;
int n;
int q;
vector<int> p[N];
bool act[N];
bool seen[N];
int e[N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;
    for (int i = 2; i <= n; i++)
    {
        if (p[i].empty())
        {
            for (int j = i; j <= n; j += i)
            {
                p[j].push_back(i);
            }
        }
    }
    while (q--)
    {
        string s;
        int x;
        cin >> s >> x;
        if (s == "+")
        {
            if (act[x])
            {
                cout << "Already on\n";
            }
            else
            {
                int conflict = 0;
                for (auto &i : p[x])
                {
                    if (seen[i])
                    {
                        conflict = e[i];
                        break;
                    }
                }
                if (conflict)
                {
                    cout << "Conflict with " << conflict << "\n";
                }
                else
                {
                    cout << "Success\n";
                    act[x] = 1;
                    for (auto &i : p[x])
                    {
                        seen[i] = 1;
                        e[i] = x;
                    }
                }
            }
        }
        else
        {
            if (act[x] == 0)
            {
                cout << "Already off\n";
            }
            else
            {
                cout << "Success\n";
                act[x] = 0;
                for (auto &i : p[x])
                {
                    seen[i] = 0;
                }
            }
        }
    }

}