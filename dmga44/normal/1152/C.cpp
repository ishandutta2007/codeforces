#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAXN 32000
#define oo ((ll)(1e18))

bool pri[MAXN];
vector<int> primos;

void criba()
{
    for(int i=2;i<MAXN;i++)
        if(!pri[i])
        {
            primos.push_back(i);
            for(int j=2*i;j<MAXN;j+=i)
                pri[j]=1;
        }
}

ll gcd(ll a,ll b)
{
    if(!b)
        return a;
    return gcd(b,a%b);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a,b;
    cin >> a >> b;
    if(a>b)
        swap(a,b);

    int dif=b-a;
    if(!dif)
    {
        db(0)
        return 0;
    }

    criba();

    vector<pii> fac;
    for(auto y : primos)
    {
        int e=0;
        while(dif%y==0)
        {
            dif/=y;
            e++;
        }
        if(e)
            fac.push_back(pii(y,e));
    }

    if(dif!=1)
        fac.push_back(pii(dif,1));

    vector<int> divs,aux;
    divs.push_back(1);
    for(auto x : fac)
    {
        int p=x.first;
        for(int e=1;e<=x.second;e++)
        {
            for(auto y : divs)
                aux.push_back(y*p);
            p*=x.first;
        }

        for(auto y : aux)
            divs.push_back(y);
        aux.clear();
    }

    ll i=a,j=b,res=oo,ok=-1;
    for(auto y : divs)
    {
        ll plu=0;
        if(a%y)
            plu=y-(a%y);
        if(res>((i+plu)*(j+plu))/gcd(i+plu,j+plu))
            ok=plu;
        if(res==((i+plu)*(j+plu))/gcd(i+plu,j+plu))
            ok=min(ok,plu);
        res=min(res,((i+plu)*(j+plu))/gcd(i+plu,j+plu));
    }
    db(ok)

    return 0;
}