#include <iostream>
#include <stack>
#include <string>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cassert>

using namespace std;
typedef long long ll;

int ask(string s)
{
    cout << "? " <<  s << endl;
    int ret; cin >> ret;
    return ret;
}

void ok(int x)
{
    cout << "! " << x << endl;
    exit(0);
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n, m; cin >> n >> m;
    vector<pair<int, int>> v;
    string s;
    s.resize(m);
    for(int i=0;i<m;i++) s[i] = '0';
    for(int i=0;i<m;i++)
    {
        s[i] = '1';
        int ret = ask(s);
        v.push_back({ret, i});
        s[i] = '0';
    }
    
    sort(v.begin(), v.end());
    
    int cost = 0;
    for(int i=0;i<m;i++)
    {
        int now = v[i].second;
        int c = v[i].first;
        
        s[now] = '1';
        int ret = ask(s);
        if(ret - cost == c)
        {
            cost = ret;
        }
        else
        {
            s[now] = '0';
        }
    }
    ok(cost);
}