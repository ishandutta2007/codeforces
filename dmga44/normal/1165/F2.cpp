#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define mod 998244353
#define MAXN 200005

int k[MAXN],f[MAXN];
vector<pii> offers;

bool check(int x)
{
    for(int i=0;i<MAXN;i++)
        f[i]=k[i];
    int b=x,p=0,add=0;
    for(int i=0;i<offers.size();i++)
    {
        b=min(b,offers[i].first);
        if(offers[i].first<=x)
        {
            int xxx=min(b,f[offers[i].second-1]);
            f[offers[i].second-1]-=xxx;
            add+=xxx;
            b-=xxx;
        }
    }

    int sum=0;
    for(int i=0;i<MAXN;i++)
        sum+=f[i];
    if(sum*2>(x-add))
        return 0;
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++)
        cin >> k[i];
    for(int i=0;i<m;i++)
    {
        int d,t;
        cin >> d >> t;
        offers.push_back(pii(d,t));
    }

    sort(offers.rbegin(),offers.rend());

    int res=0;
    for(int i=(1<<18);i;i>>=1)
        if(!check(res+i))
            res+=i;
    res++;
    db(res)

    return 0;
}