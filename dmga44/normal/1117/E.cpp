#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef double ld;
typedef pair<ll,ll> pii;
typedef pair<ll,pii> pip;
typedef pair<pii,ll> ppi;
typedef pair<pii,pii> ppp;
typedef pair<ld,ll> pli;
typedef pair<pii,string> pps;
typedef pair<string,ll> psi;
typedef pair<ll,char> pic;
typedef pair<char,ll> pci;
typedef complex<double> point;
typedef vector<point> polygon;
#define pi (acos(-1))
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ll, null_type, less<ll>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define MAXN 10005

char imp[MAXN][3];
vector<int> vp[3][26];
vector<int> pos[3][MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string t,t1,t2,t3;
    cin >> t;
    int n=t.size();
    cout << "? ";
    for(int i=0;i<n;i++)
    {
        imp[i][0]=(i%26)+'a';
        vp[0][i%26].push_back(i);
        cout << imp[i][0];
    }
    cout << '\n';
    cout.flush();
    cin >> t1;
    for(int i=0;i<n;i++)
        for(auto y : vp[0][t1[i]-'a'])
            pos[0][i].push_back(y);

    cout << "? ";
    for(int i=0;i<n;i++)
    {
        imp[i][1]=((i/26)%26)+'a';
        cout << imp[i][1];
    }
    cout << '\n';
    cout.flush();
    cin >> t2;
    for(int i=0;i<n;i++)
        for(auto y : pos[0][i])
            if(imp[y][1]==t2[i])
                pos[1][i].push_back(y);

    cout << "? ";
    for(int i=0;i<n;i++)
    {
        imp[i][2]=((i/676)%26)+'a';
        cout << imp[i][2];
    }
    cout << '\n';
    cout.flush();
    cin >> t3;
    for(int i=0;i<n;i++)
        for(auto y : pos[1][i])
            if(imp[y][2]==t3[i])
                pos[2][i].push_back(y);

    vector<pic> vvv;
    for(int i=0;i<n;i++)
        vvv.push_back(pic(pos[2][i][0],t[i]));
    sort(vvv.begin(),vvv.end());

    cout << "! ";
    for(int i=0;i<n;i++)
        cout << vvv[i].second;
    cout << '\n';
    cout.flush();

    return 0;
}