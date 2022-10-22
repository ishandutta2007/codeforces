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
typedef pair<ld,ld> pdd;
typedef pair<double,ll> pdi;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(0x3f3f3f3f)
#define pi acos(-1)
#define MAXN (ll)(5e5+5)

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        vector<int> fs(26);
        for(auto y : s)
            fs[y-'a']++;
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i=0;i<n;i++)
            cin >> a[i];
        vector<char> res(n);
        vector<bool> mk(n);
        int pos=25;
        int cc=0;
        while(cc<n)
        {
            int cant=0;
            vector<int> p;
            for(int i=0;i<n;i++)
            {
                if(mk[i])
                    continue;
                int res=0;
                for(int j=0;j<n;j++)
                    if(mk[j])
                        res+=abs(i-j);
                if(res==a[i])
                {
                    cant++;
                    p.push_back(i);
                }
            }
            while(fs[pos]<cant)
                pos--;
            for(auto y : p)
            {
                mk[y]=1;
                res[y]=('a'+pos);
            }
            cc+=cant;
            pos--;

        }

        for(int i=0;i<n;i++)
            cout << res[i];
        cout << '\n';
    }

    return 0;
}