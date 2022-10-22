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
        int n,m,a,b;
        cin >> n >> m >> a >> b;
        b=min(b,a*2);
        char c;
        ll res=0;
        for(int i=0;i<n;i++)
        {
            int last=0;
            for(int j=0;j<m;j++)
            {
                cin >> c;
                if(c=='.')
                {
                    if(last==-1)
                        last=j;
                }
                else
                {
                    if(last!=-1)
                    {
                        int sz=j-last;
                        res+=((sz/2)*b+(sz&1)*a);
                        last=-1;
                    }
                }
            }
            if(last!=-1)
            {
                int sz=m-last;
                res+=((sz/2)*b+(sz&1)*a);
                last=-1;
            }
        }
        db(res)
    }
    return 0;
}
/**
4
1 1 10 1
.
1 2 10 1
..
2 1 10 1
.
.
3 3 3 7
..*
*..
.*.

1
1 4 10 1
..*.
**/