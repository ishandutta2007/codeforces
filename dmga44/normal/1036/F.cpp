#include <bits/stdc++.h>
#define endl '\n'
#define db(x) cout << x << endl;
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
#define MAXN 1005
#define oo 1000000000000000001ll

int pri[MAXN];

ll qp(ll b,ll e)
{
    if(!e)
        return 1;
    ll inter=qp(b,e>>1);
    if(inter==-1 || oo/inter<inter)
        return -1;
    inter=(inter*inter);
    if(e&1)
    {
        if(oo/b<inter)
            return -1;
        inter=(inter*b);
    }
    return inter;
}

void criba()
{
    for(int i=2;i<MAXN;i++)
    {
        if(!pri[i])
        {
            pri[i]=1;
            for(int j=2*i;j<MAXN;j+=i)
            {
                if(j%(i*i)==0)
                    pri[j]=-70;
                else
                    pri[j]++;
            }
        }
    }
}

ll r(ll x,ll p)
{
    ll res=1;
    for(ll j=(1<<(60/p));j;j>>=1)
    {
        ll xxx=qp(res+j,p);
        if(xxx!=-1 && xxx<=x)
            res+=j;
    }
    res--;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

//    int n;
//    cin >> n;
//    for(int i=0;i<n;i++)
//        cin >> ax[i] >> ay[i] >> bx[i] >> by[i];

    criba();

    int n;
    ll x;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> x;
        ll res=x;
        for(int j=2;j<61;j++)
        {
            if(pri[j]<0)
                continue;
            if(pri[j]&1)
                res-=r(x,j);
            else if(pri[j]>0)
                res+=r(x,j);
        }
        db(res-1)
    }

    return 0;
}