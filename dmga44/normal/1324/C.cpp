#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
#define MAXN 5005

int a[MAXN];
bool mk[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        s="R"+s+"R";
        int last=0;
        int res=0;
        for(int i=1;i<s.size();i++)
        {
            if(s[i]=='R')
            {
                res=max(res,i-last);
                last=i;
            }
        }
        db(res)
    }

    return 0;
}