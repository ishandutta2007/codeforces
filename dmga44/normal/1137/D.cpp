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

int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);

    int k;
    while(1)
    {
        cout << "next " << "1 2 3 4 5 6 7 8 9" << '\n';
        cout.flush();
        cin >> k;
        string s;
        getline(cin,s);
        cout << "next " << "1" << '\n';
        cout.flush();
        cin >> k;
        getline(cin,s);
        if(k==2)
            break;
    }

    while(1)
    {
        cout << "next " << "0 1 2 3 4 5 6 7 8 9" << '\n';
        cout.flush();
        cin >> k;
        string s;
        getline(cin,s);
        if(k==1)
            break;
    }
    cout << "done\n";
    cout.flush();

    return 0;
}