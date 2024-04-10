#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
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
        int a,b,c;
        cin >> a >> b >> c;
        int res=0;
        if(a)
        {
            a--;
            res++;
        }
        if(b)
        {
            b--;
            res++;
        }
        if(c)
        {
            c--;
            res++;
        }

        vector<int> v(3);
        v[0]=a;
        v[1]=b;
        v[2]=c;

        sort(v.begin(),v.end());

        if(v[0])
        {
            if(v[0]>=3)
                res+=4;
            else if(v[0]==2)
                res+=3;
            else
            {
                if(v[2]>=2)
                    res+=2;
                else
                    res++;
            }
        }
        else
        {
            if(v[1])
                res++;
        }
        db(res)
    }

    return 0;
}