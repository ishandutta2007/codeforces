#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<int,pii> pip;
typedef pair<pii,pii> ppp;
#define MAXN 2000005

int ac[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll a,b,c,d;
    cin >> a >> b >> c >> d;
    for(int i=a;i<=b;i++)
    {
        ac[i+b]+=1;
        ac[i+c+1]+=-1;
    }

    for(int i=1;i<MAXN;i++)
        ac[i]=ac[i-1]+ac[i];

    ll res=0,sum=0;
    for(int i=MAXN;i>d;i--)
        sum+=ac[i];
    for(int i=d;i>=c;i--)
    {
//        db(sum)
        res+=sum;
        sum+=ac[i];
    }
    db(res)

    return 0;
}