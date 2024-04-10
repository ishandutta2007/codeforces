#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    set<string> s[11];
    vector<string> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    char delim;
    cin >> delim;
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        s[0].insert(v[i]+delim);
        s[v[i].size()].insert(v[i]+delim);
        cnt+=v[i].size();
    }
    cnt/=(n/2);
    for(int i=0;i<n/2;i++)
    {
        string t=*s[0].begin();
        s[0].erase(t);
        s[t.size()-1].erase(t);
        cout << t;
        t=*s[cnt-t.size()+1].begin();
        s[0].erase(t);
        s[t.size()-1].erase(t);
        t.pop_back();
        cout << t << endl;
    }
    return 0;
}