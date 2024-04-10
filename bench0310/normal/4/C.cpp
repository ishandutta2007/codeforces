#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    map<string,int> m;
    string s;
    for(int i=0;i<n;i++)
    {
        cin >> s;
        if(m.find(s)==m.end())
        {
            m.insert(make_pair(s,0));
            cout << "OK" << endl;
        }
        else cout << s+to_string(++m[s]) << endl;
    }
    return 0;
}