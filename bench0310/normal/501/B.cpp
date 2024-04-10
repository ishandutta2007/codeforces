#include <bits/stdc++.h>

using namespace std;

int main()
{
    int q;
    cin >> q;
    map<string,string> m;
    while(q--)
    {
        string s,t;
        cin >> s >> t;
        if(m.find(s)!=m.end())
        {
            m[t]=m[s];
            m.erase(s);
        }
        else m[t]=s;
    }
    cout << m.size() << endl;
    for(pair<string,string> p:m) cout << p.second << " " << p.first << endl;
    return 0;
}