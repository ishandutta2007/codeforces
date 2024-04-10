#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<ll,pii> pip;
typedef pair<pii,ll> ppi;
typedef pair<pii,pii> ppp;
typedef pair<ld,ll> pli;
typedef pair<pii,string> pps;
typedef pair<char,ll> pci;
typedef complex<double> point;
typedef vector<point> polygon;
#define pi (acos(-1))
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ll, null_type, less<ll>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;

vector<int> fl[27],fr[27];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    string l,r;
    cin >> l >> r;
    for(int i=0;i<l.size();i++)
    {
        if(l[i]!='?')
            fl[l[i]-'a'].push_back(i);
        else
            fl[26].push_back(i);
    }

    for(int i=0;i<r.size();i++)
    {
        if(r[i]!='?')
            fr[r[i]-'a'].push_back(i);
        else
            fr[26].push_back(i);
    }

    int res=0;
    for(int i=0;i<26;i++)
    {
        while(fl[i].size()<fr[i].size() && fl[26].size())
        {
            int x=fl[26].back();
            fl[26].pop_back();
            fl[i].push_back(x);
        }
        while(fl[i].size()>fr[i].size() && fr[26].size())
        {
            int x=fr[26].back();
            fr[26].pop_back();
            fr[i].push_back(x);
        }
        res+=min(fl[i].size(),fr[i].size());
    }
    res+=min(fl[26].size(),fr[26].size());

    db(res)
    for(int i=0;i<27;i++)
    {
        int mi=min(fl[i].size(),fr[i].size());
        for(int j=0;j<mi;j++)
            cout << fl[i][j]+1 << ' ' << fr[i][j]+1 << '\n';
    }

    return 0;
}