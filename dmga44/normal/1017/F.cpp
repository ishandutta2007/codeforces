#include <bits/stdc++.h>
#define endl '\n'
#define db(x) cout << x << endl;
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
#define mod (1ll<<32)

vector<bool> pri(128000000);
unsigned int res,a,b,c,d,n;

int cal1(int x)
{
    ll res=1;
    if(x&1)
        res+=4;
    res+=(x/2)*6;
    return res;
}

unsigned int cal2(unsigned int x)
{
    return a*x*x*x+b*x*x+c*x+d;
}

int cal3(int x)
{
    ll res=0;
    int nn=n;
    while(nn)
    {
        res+=(nn/x);
        nn/=x;
    }
    return res;
}

int calc4(int x)
{
    return (cal2(x)*cal3(x))%mod;
}

int calc5(int x)
{
    if(((x%2)==0) || ((x%3)==0))
        return -1;
    if(x%6==1)
        return (x/6)*2;
    return (x/6)*2+1;
}

void criba()
{
    res+=calc4(2)+calc4(3);
    for(int i=1;i<128000000;i++)
    {
        ll x=cal1(i);
        if(x>n)
            return;
        if(pri[i])
            continue;
        res+=calc4(x);
        if(x>18000)
            continue;
        for(int j=x*x;j<=n;j+=(2*x))
        {
            ll aux=calc5(j);
            if(aux==-1)
                continue;
            pri[aux]=1;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> a >> b >> c >> d;
    criba();
    db(res)

    return 0;
}