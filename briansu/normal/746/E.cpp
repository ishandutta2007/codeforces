#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
#define REP(i,n) for(int i=0;i<n;i++)
#define FILL(i,n) memset(i,n,sizeof(i));
#define A first
#define B second
#define pb push_back
#ifdef brian
#define  debug(...) do{\
    fprintf(stderr,"%s - %d : (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
    _do(__VA_ARGS__);\
}while(0)
template<typename t> void _do(t &&x){cerr<<x<<endl;}
template<typename t,typename ...T> void _do(t &&x,T &&...tail){cerr<<x<<", ";_do(tail...);}
#else
#define debug(...)
#endif // brian
const ll INF=ll(1e18);

ll d[200005],no=1,ne=2,e=0,o=0;
set<ll> dt;
ll n,m;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    REP(i,n)
    {
        cin>>d[i];
        if(d[i]%2)o++;
        else e++;
    }
    o=n/2-o;
    e=n/2-e;
    debug(o,e);
    REP(i,n)
    {
        if(!dt.count(d[i]))dt.insert(d[i]);
        else
        {
            if(d[i]%2)o++;
            else e++;
            d[i]=-1;
        }
    }
    ll ans=0;
    REP(i,n)
    {
        debug(i,e,o);
        if(d[i]==-1)
        {
            if(o>0)
            {
                while(dt.count(no))no+=2;
                if(no>m){cout<<-1<<endl;return 0;}
                d[i]=no;
                no+=2;
                o--;
                ans++;
            }
            else
            {
                while(dt.count(ne))ne+=2;
                if(ne>m){cout<<-1<<endl;return 0;}
                d[i]=ne;
                ne+=2;
                e--;
                ans++;
            }
        }
        else if(d[i]%2==1&&e>0&&o<0)
        {
            while(dt.count(ne))ne+=2;
            if(ne>m){cout<<-1<<endl;return 0;}
            d[i]=ne;
            ne+=2;
            e--;
            o++;
            ans++;
        }
        else if(d[i]%2==0&&o>0&&e<0)
        {
            while(dt.count(no))no+=2;
            if(no>m){cout<<-1<<endl;return 0;}
            d[i]=no;
            no+=2;
            o--;
            e++;
            ans++;
        }

    }
    cout<<ans<<endl;
    REP(i,n)cout<<(i==0?"":" ")<<d[i];
    cout<<endl;

}