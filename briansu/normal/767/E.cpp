#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
#define REP(i,n) for(int i=0;i<n;i++)
#define FILL(i,n) memset(i,n,sizeof(i));
#define SZ(A) ((int)A.size())
#define ALL(A) A.begin(),A.end()
#define X first
#define Y second
#define pb push_back
#ifdef brian
#define  debug(...) do{\
    fprintf(stderr,"%s - %d : (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
    _do(__VA_ARGS__);\
}while(0)
template<typename t> void _do(t &&_x){cerr<<_x<<endl;}
template<typename t,typename ...T> void _do(t &&_x,T &&...tail){cerr<<_x<<", ";_do(tail...);}
#else
#define debug(...)
#define endl '\n'
#endif // brian

const ll INF=ll(1e15);
const ll MAXn=1e5+5,MAXlg=20;
const ll MOD = 1000000007;

ll n,m;

priority_queue<ii,vector<ii>,greater<ii> > pq;
ll c[MAXn],w[MAXn];
ii ans[MAXn];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    REP(i,n)cin>>c[i];
    REP(i,n)cin>>w[i];
    ll tt=0;
    REP(i,n)
    {
        ans[i].X=c[i]/100;
        ans[i].Y=c[i]%100;
        m-=ans[i].Y;
        if(ans[i].Y!=0)pq.push(ii(w[i]*(100-ans[i].Y),i));
        if(m<0)
        {
            ii tmp=pq.top();
            pq.pop();
            tt+=tmp.X;
            ans[tmp.Y].X++;
            ans[tmp.Y].Y=0;
            //pq.push(ii(w[tmp.Y]*100,tmp.Y));
            m+=100;
        }
    }
    cout<<tt<<endl;
    REP(i,n)cout<<ans[i].X<<" "<<ans[i].Y<<endl;

}