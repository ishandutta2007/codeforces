#include <bits/stdc++.h>
#define android ios

using namespace std;

int main()
{
    android::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<int> v;
    long long k;
    cin >> k;
    char c;
    long long s = 0;
    while (cin >> c)
    {
        s += c - '0';
        v.push_back(c - '0');
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        if (s >= k)
        {
            cout << i << endl;
            return 0;
        }
        s += 9 - v[i];
    }
    cout << v.size() << endl;
    return 0;
}