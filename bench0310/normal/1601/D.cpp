#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,d;
    cin >> n >> d;
    vector<array<int,2>> b,c;
    for(int i=0;i<n;i++)
    {
        int s,a;
        cin >> s >> a;
        if(s>=d)
        {
            if(a<=s) b.push_back({a,s});
            else c.push_back({s,a});
        }
    }
    ranges::sort(b);
    ranges::sort(c);
    multiset<int> o;
    int idx=0;
    int sz=b.size();
    for(auto [a,s]:b) o.insert(s);
    vector<array<int,2>> v;
    for(auto [s,a]:c)
    {
        while(idx<sz&&b[idx][0]<=s) o.erase(o.find(b[idx++][1]));
        if(o.empty()||(*o.begin())>=a) v.push_back({a,s});
    }
    ranges::sort(v);
    int lim=d;
    int good=0;
    for(auto [a,s]:v)
    {
        if(s>=lim)
        {
            lim=a;
            good++;
        }
    }
    cout << sz+good << "\n";
    return 0;
}