#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;

ll ask(int n,vector<int> &pos)
{
    set<int> s;
    for(int i=0;i<n;i++)
        s.insert(i);
    for(auto y : pos)
        s.erase(y);

    if(!s.size())
        return 0;
    cout << "? " << s.size();
    for(auto y : s)
        cout << ' ' << y+1;
    cout << '\n';
    cout.flush();
    ll res;
    cin >> res;
    return res;
}

int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);

    int n;
    cin >> n;
    vector<int> oks;
    for(int i=0;i<(1<<13);i++)
        if(__builtin_popcount(i)==6 && oks.size()<n)
            oks.push_back(i);

    vector<int> ps[13];
    for(int i=0;i<n;i++)
        for(int j=0;j<13;j++)
            if(oks[i]&(1<<j))
                ps[j].push_back(i);

    vector<ll> ans(13);
    for(int i=0;i<13;i++)
        ans[i]=ask(n,ps[i]);

    cout << "!";
    for(int i=0;i<n;i++)
    {
        ll res=0;
        for(int j=0;j<13;j++)
            if(oks[i]&(1<<j))
                res|=ans[j];
        cout << ' ' << res;
    }
    cout << '\n';
    cout.flush();

    return 0;
}