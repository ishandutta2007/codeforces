#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
#define REP(i,n) for(int i=0;i<n;i++)
#define FILL(i,n) memset(i,n,sizeof(i));
#define X first
#define Y second
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

const ll INF=ll(1e15);
const ll MAXn=100005;

ll n,l,r,mn;
ll a[MAXn],b[MAXn];
ii c[MAXn];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>l>>r;
    REP(i,n)cin>>a[i];
    REP(i,n)
    {
        cin>>c[i].X;
        c[i].Y=i;
    }
    sort(c,c+n);
    b[c[0].Y]=l;
    mn=l-a[c[0].Y];
    for(int i=1;i<n;i++)
    {
        mn=max(mn+1,l-a[c[i].Y]);
        b[c[i].Y]=mn+a[c[i].Y];
    }
    REP(i,n)
    {
        if(b[i]<l||b[i]>r)
        {
            cout<<"-1"<<endl;
            return 0;
        }
    }
    REP(i,n)cout<<(i==0?"":" ")<<b[i];
    cout<<endl;

}