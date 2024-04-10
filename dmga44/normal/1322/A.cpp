#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    string s;
    cin >> s;
    int res=0,sum=0,last0=0,ok=1;
    for(int i=0;i<n;i++)
    {
        int v=1;
        if(s[i]==')')
            v=-1;
        sum+=v;
        ok&=(sum>=0);
        if(sum==0)
        {
            if(!ok)
                res+=(i+1-last0);
            ok=1;
            last0=i+1;
        }
    }

    if(sum)
        db(-1)
    else
        db(res)

    return 0;
}