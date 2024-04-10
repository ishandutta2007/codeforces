#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;

typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
const double EPS=(1e-13);
const ll INF=ll(1e18);
const int sINF=int(1e9);
using namespace std;
using namespace __gnu_pbds;
#define REP(i,n) for(int i=0;i<n;i++)
#define FILL(n,i) memset(n,i,sizeof n)
#ifdef brian
#define debug(...){\
    fprintf(stderr,"%s - %d : (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
    _DO(__VA_ARGS__);\
}while(0)
template<typename I>void _DO(I &&x){cerr<<x<<endl;}
template<typename I,typename ...T> void _DO(I &&x,T &&...tail){cerr<<x<<", ";_DO(tail...);}
#else
#define debug(...)
#endif // brian
bool v[101];
ll d[101];
ll n;
set<ll> allow;
bool dfs(ll now,ll home,ll it)
{
    it++;
    v[now]=1;
    if(d[now]==home)
    {
        if(it%2==0)allow.insert(it/2);
        else allow.insert(it);
        return 1;
    }
    if(!v[d[now]])return dfs(d[now],home,it);
    else return 0;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    cin>>n;
    REP(i,n){cin>>d[i];d[i]--;}

    FILL(v,0);
    REP(i,n)
    {
        if(!v[i])
        {
            if(!dfs(i,i,0))
            {
                cout<<-1<<endl;
                return 0;
            }
        }
    }
    ll a=1;
    set<ll>::iterator it=allow.begin();
    for(;it!=allow.end();it++)
    {
        ll b=__gcd(a,*it);
        a=(*it)/b*a;
        debug(*it);
    }
    cout<<a<<endl;
}