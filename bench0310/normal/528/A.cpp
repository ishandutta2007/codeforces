#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int w,h,n;
    cin >> w >> h >> n;
    set<int> c[2];
    multiset<int> s[2];
    c[0].insert(0);
    c[0].insert(h);
    c[1].insert(0);
    c[1].insert(w);
    s[0].insert(h);
    s[1].insert(w);
    while(n--)
    {
        char t;
        int x;
        cin >> t >> x;
        int id=(t=='V');
        auto it=c[id].lower_bound(x);
        int r=*it;
        it--;
        int l=*it;
        c[id].insert(x);
        s[id].erase(s[id].find(r-l));
        s[id].insert(x-l);
        s[id].insert(r-x);
        cout << (ll)(*s[0].rbegin())*(*s[1].rbegin()) << "\n";
    }
    return 0;
}