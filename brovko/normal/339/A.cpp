#include <bits/stdc++.h>

using namespace std;

main()
{
    string s;
    cin >> s;

    vector <char> v;

    for(int i = 0; i < s.size(); i += 2)
        v.push_back(s[i]);

    sort(v.begin(), v.end());

    for(int i = 0; i < v.size(); i++)
    {
        cout << v[i];

        if(i + 1 < v.size())
            cout << '+';
    }
}