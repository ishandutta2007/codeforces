#include <bits/stdc++.h>
#define endl '\n'
#define db(x) cout << x << endl;
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
#define mod 1000000007
#define oo 400000000

map<int,int> m;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,x;
    cin >> n;
    ll res=1;
    set<int> vals,vs;
    int lim[2];
    lim[0]=-oo;
    lim[1]=oo;
    string s;
    for(int i=0;i<n;i++)
    {
        cin >> s >> x;
        vs.insert(x);
        if(s[1]=='D')
        {
            m[x]=2;
            vals.insert(x);
        }
        else
        {
            if(x>lim[0] && x<lim[1])
                res=(res*2)%mod;
            else if(!(x==lim[0] || x==lim[1]))
                res=0;
            auto it=vals.find(x);
            if(it!=vals.begin())
            {
                it--;
                lim[0]=*(it);
                it++;
            }
            else
                lim[0]=-oo;
            it++;
            if(it!=vals.end())
                lim[1]=*(it);
            else
                lim[1]=oo;
            vals.erase(x);
        }
    }

    for(auto y : vals)
        if(!(y>lim[0] && y<lim[1]))
            m[y]=1;

    ll cont=1;
    for(auto y : vals)
        if(m[y]==2)
            cont++;

    db((res*cont)%mod)

    return 0;
}