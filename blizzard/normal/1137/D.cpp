#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int max(int a, int b)
{ return (a > b) ? a : b; }

const int MAXN = 1031;

int a[10];

void checkans()
{
    int x;
    cin >> x;
    for (int i = 0; i < x; i++)
    {
        string s;
        cin >> s;
        for (char c : s)
        {
            a[c - '0'] = i;
        }
    }
}

void go(vector<int> v)
{
    cout << "next ";
    for (int x : v)
    {
        cout << x << " ";
    }
    cout << endl;
    checkans();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    do {
        go({0, 1});
        go({1});
    } while (a[0] != a[1]);

    do {
        go({0, 2});
    } while (a[0] != a[1]);

    do {
        if (a[0] == a[2])
        {
            go({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
        } else {
            go({2, 3, 4, 5, 6, 7, 8, 9});
        }
    } while (a[2] != a[3]);

    cout << "done" << endl;
    return 0;
}