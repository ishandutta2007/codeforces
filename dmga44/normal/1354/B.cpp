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
        int p[3];
        p[0]=p[1]=p[2]=-1;
        int n=s.size();
        int res=1e6;
        for(int i=0;i<n;i++)
        {
            p[s[i]-'1']=i;
            int x=min(p[0],min(p[1],p[2]));
            if(x!=-1)
                res=min(res,i-x+1);
        }
        if(res==1e6)
            db(0)
        else
            db(res)
    }

    return 0;
}