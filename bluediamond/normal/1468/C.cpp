/**
 ____ ____ ____ ____ ____
||a |||t |||o |||d |||o ||
||__|||__|||__|||__|||__||
|/__\|/__\|/__\|/__\|/__\|

**/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int q;

set <pair <int, int>> s1;
set <pair <int, int>> s2;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> q;
    int curr = 0;
    while(q--)
    {
        int op;
        cin >> op;
        if(op == 1)
        {
            int val;
            cin >> val;
            val = -val;
            curr++;
            s1.insert(make_pair(curr, val));
            s2.insert(make_pair(val, curr));
        }
        else if(op == 2)
        {
            set <pair <int, int>> :: iterator it = s1.begin();
            cout << it->first << " ";
            s1.erase(s1.begin());
            s2.erase(make_pair(it->second, it->first));
        }
        else
        {
            set <pair <int, int>> :: iterator it = s2.begin();
            cout << it->second << " ";
            s2.erase(s2.begin());
            s1.erase(make_pair(it->second, it->first));
        }
    }
    cout << "\n";
    return 0;
}