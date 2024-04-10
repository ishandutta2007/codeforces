#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<ll,pii> pip;
#define MAXN 110005

vector<int> primes;
int mk[MAXN];

void criba()
{
    for(int i=2;i<MAXN;i++)
        if(!mk[i])
        {
            primes.push_back(i);
            for(int j=2*i;j<MAXN;j+=i)
                mk[j]=1;
        }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    criba();

    int t;
    cin >>t;
    while(t--)
    {
        ll a,m;
        cin >> a >> m;
        ll x=__gcd(a,m);
        m/=x;
        ll mm=m;

        vector<ll> dp;
        for(auto y : primes)
            if((m%y)==0)
            {
                dp.push_back(y);
                while((m%y)==0)
                    m/=y;
            }
        if(m!=1)
            dp.push_back(m);

        if(dp.size())
            for(auto y : dp)
            {
                mm/=y;
                mm*=(y-1);
            }
        db(mm)
    }

    return 0;
}