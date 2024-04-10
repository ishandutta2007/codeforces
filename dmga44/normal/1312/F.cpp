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
#define MAXN 300005

int g[MAXN][3],x,y,z;
map<int,int> last;
ll xs[MAXN],pp[MAXN],r[MAXN];

int mex(vector<int> v)
{
    int res=0;
    while(1)
    {
        bool ok=0;
        for(auto y : v)
            ok|=(y==res);
        if(ok)
            res++;
        else
            break;
    }
    return res;
}

int hs(int pos)
{
    int h=0;
    for(int i=0;i<=4;i++)
        for(int j=0;j<3;j++)
            h=h*4+g[pos-5+i][j];
    return h;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n >> x >> y >> z;
        int pos=1;
        while(1)
        {
            vector<int> m1;
            m1.push_back(g[max(0,pos-x)][0]);
            m1.push_back(g[max(0,pos-y)][1]);
            m1.push_back(g[max(0,pos-z)][2]);
            g[pos][0]=mex(m1);

            vector<int> m2;
            m2.push_back(g[max(0,pos-x)][0]);
            m2.push_back(g[max(0,pos-z)][2]);
            g[pos][1]=mex(m2);

            vector<int> m3;
            m3.push_back(g[max(0,pos-x)][0]);
            m3.push_back(g[max(0,pos-y)][1]);
            g[pos][2]=mex(m3);

            if(pos>=5)
            {
                ll h=hs(pos);
                if(!last[h])
                    last[h]=pos+1;
                else
                    break;
            }
            pos++;
        }
//        for(int i=0;i<=pos;i++)
//            cout << i << ' ';
//        db("")
//        for(int i=0;i<=pos;i++)
//            cout << g[i][0] << ' ';
//        db("")
//        for(int i=0;i<=pos;i++)
//            cout << g[i][1] << ' ';
//        db("")
//        for(int i=0;i<=pos;i++)
//            cout << g[i][2] << ' ';
//        db("")


        int h=hs(pos);
        ll cycle_len=pos+1-last[h];
        ll xsum=0;
        for(int i=0;i<n;i++)
        {
            cin >> xs[i];
            ll p=xs[i];
            if(xs[i]>pos)
            {
                ll dif=(xs[i]-pos)%cycle_len;
                p=pos-cycle_len+dif;
            }
            pp[i]=p;

            r[i]=g[p][0];
            xsum^=r[i];
//            db(r[i])
        }
//        db("")

        if(xsum==0)
            db(0)
        else
        {
            int res=0;
            for(int i=0;i<n;i++)
            {
                ll p=pp[i];
                vector<int> v;
                v.push_back(g[max(0ll,p-x)][0]);
                v.push_back(g[max(0ll,p-y)][1]);
                v.push_back(g[max(0ll,p-z)][2]);

                for(auto y : v)
                    if(y==(xsum^r[i]))
                        res++;
            }
            db(res)
        }

        last.clear();

    }

    return 0;
}
/**
1
4 5 5 5
2 10 4 2
**/