#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef long double ld;
typedef pair<pii,string> pps;
typedef pair<char,int> pci;
#define pi (acos(-1))
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ll, null_type, less<ll>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        if(s[0]=='<' && s[n-1]=='>')
        {
            int s1=0;
            for(int i=0;i<n;i++)
            {
                if(s[i]=='<')
                    s1++;
                else
                    break;
            }

            int s2=0;
            for(int i=n-1;i>=0;i--)
            {
                if(s[i]=='>')
                    s2++;
                else
                    break;
            }
            db(min(s1,s2))
        }
        else
            db(0)
    }

    return 0;
}