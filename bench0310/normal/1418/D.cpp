#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,q;
    cin >> n >> q;
    set<int> s;
    multiset<int> m;
    auto add=[&](int x)
    {
        auto it=s.insert(x).first;
        if(next(it)!=s.end()&&it!=s.begin()) m.erase(m.find(*next(it)-*prev(it)));
        if(next(it)!=s.end()) m.insert(*next(it)-x);
        if(it!=s.begin()) m.insert(x-*prev(it));
    };
    auto rm=[&](int x)
    {
        s.erase(x);
        auto it=s.lower_bound(x);
        if(it!=s.end()) m.erase(m.find(*it-x));
        if(it!=s.begin()) m.erase(m.find(x-*prev(it)));
        if(it!=s.end()&&it!=s.begin()) m.insert(*it-*prev(it));
    };
    for(int i=0;i<n;i++)
    {
        int x;
        cin >> x;
        add(x);
    }
    auto solve=[&]()->ll
    {
        if(s.size()<=1) return 0;
        else return (*s.rbegin()-*s.begin()-*m.rbegin());
    };
    cout << solve() << "\n";
    while(q--)
    {
        int t,x;
        cin >> t >> x;
        if(t==0) rm(x);
        else add(x);
        cout << solve() << "\n";
    }
    return 0;
}