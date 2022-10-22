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
#define MAXN 1005

ll p[MAXN];
vector<ll> primes;
bool mk[MAXN];

void criba()
{
    for(int i=2;i<MAXN;i++)
    {
        if(!p[i])
        {
            primes.push_back(i);
            for(int j=2*i;j<MAXN;j+=i)
                p[j]=1;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    criba();

    vector<ll> qs;
    int ini=141;
//    db(primes[ini])
    for(int i=ini;i>=0;i--)
    {
        if(mk[i])
            continue;
        ll mul=primes[i];
        mk[i]=1;
        for(int j=i-1;j>=0;j--)
        {
            if(mk[j])
                continue;
            if(1e18/primes[j]>mul)
            {
                mul*=primes[j];
                mk[j]=1;
            }
        }
//        db(mul)
        qs.push_back(mul);
    }
//    db(qs.size())

    int t;
    cin >> t;
    while(t--)
    {
        vector<int> ans(22);
        for(int i=0;i<19;i++)
        {
            cout << "? " << qs[i] << endl;
            cout.flush();
            cin >> ans[i];
        }

        vector<ll> pp;
        for(int i=0;i<19;i++)
            for(auto y : primes)
                if(!(ans[i]%y))
                    pp.push_back(y);

        vector<int> v2;
//        db(pp.size())
        if(pp.size()<=3)
        {
            for(auto y : pp)
            {
                ll ad=1;
                while(ad<1e9)
                    ad*=y;
                ad/=y;
                cout << "? " << ad << endl;
                cout.flush();
                int x;
                cin >> x;
                v2.push_back(x);
            }
        }
        else
        {
            ll ma=1e9,l=2;
            if(pp.size()>6)
            {
                ma=1e6;
                l=3;
            }
            vector<ll> pos;
            for(auto y : pp)
            {
                ll ad=1;
                while(ad<ma)
                    ad*=y;
                ad/=y;
                pos.push_back(ad);
            }

            for(int i=0;i<pos.size();i+=l)
            {
                ll ad=1;
                for(int j=i;j<pos.size() && j-i<l;j++)
                    ad*=pos[j];
                cout << "? " << ad << endl;
                cout.flush();
                int x;
                cin >> x;
                v2.push_back(x);
            }
        }

        int cant=1;
        for(auto y : v2)
        {
            int mul=0;
            for(int i=1;i*i<=y;i++)
                if(y%i==0)
                {
                    if(i!=y/i)
                        mul++;
                    mul++;
                }
            cant*=mul;
        }
        cout << "! " << cant*2 << '\n';
        cout.flush();
    }

    return 0;
}
/**
1
1
1
1
1
1
1
1
1
1
1
1
1
2
1
1
1
1
1
1
4194304
**/