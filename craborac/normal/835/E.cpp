#include <bits/stdc++.h>
#define android ios

using namespace std;

int main()
{
    android::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, x, y;
    cin >> n >> x >> y;
    int used[10];
    fill(used, used + 10, 0);
    int a = 0, b = 0, d = 0;
    int t = -1;
    for (int i = 0; i < 10; i++)
    {
        vector<int> v;
        for (int j = 1; j <= n; j++)
            if (j & (1 << i))
                v.push_back(j);
        int c = 0;
        if (v.size())
        {
            cout << "? " << v.size() << " ";
            for (auto tt: v)
                cout << tt << " ";
            cout << endl;
            cin >> c;
        }
        if (c == y || c == (x ^ y))
        {
            used[i] = 1;
            t = i;
        }
    }
    b = (1 << t);
    d = (1 << t);
    for (int i = 0; (1 << i) <= n; i++)
    {
        if (i != t)
        {
            vector<int> v;
            d += (1 << i);
            for (int j = 1; j <= n; j++)
            {
                if ((j & d) == (a + (1 << i)))
                    v.push_back(j);
            }
            int c = 0;
            if (v.size())
            {
                cout << "? " << v.size() << " ";
                for (auto tt: v)
                    cout << tt << " ";
                cout << endl;
                cin >> c;
            }
            int add = 0;
            if (c == y || c == (x ^ y))
                add = (1 << i);
            a += add;
            if (used[i])
                b += (1 << i) - add;
            else
                b += add;
        }
    }
    cout << "!" << " " << a << " " << b << endl;
    return 0;
}