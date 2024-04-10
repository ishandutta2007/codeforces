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
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;

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
        int n=s.size();
        vector<int> ac(n+1);
        for(int i=0;i<n;i++)
        {
            ac[i+1]=ac[i];
            ac[i+1]+=(s[i]=='1');
        }

        int res=10000;
        for(int i=0;i<=n;i++)
        {
            int t1=i;
            int t2=n-i;
            int c11=ac[i];
            int c12=ac[n]-ac[i];
            res=min(res,c11+(t2-c12));
            res=min(res,c12+(t1-c11));
        }
        db(res)
    }

    return 0;
}