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
        int mi=105;
        int ma=-1;
        int cont=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='1')
            {
                cont++;
                mi=min(mi,i);
                ma=max(ma,i);
            }
        }

        if(ma!=-1)
            db(ma-mi+1-cont)
        else
            db(0)
    }

    return 0;
}