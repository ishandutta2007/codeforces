#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<int,int> ii;
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

const ll INF=ll(1e18);

const ll MAXn=500005;
const ll MAXlg=19;

ll n;
ll fm[105];
bool ok[105];
ll d[105];
int main()
{
    d[0]=0;ok[0]=1;
    cin>>n;
    for(int i=1;i<=n;i++){cin>>d[i];d[i]+=d[i-1];}
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(ok[j]&&d[i]-d[j]!=0)
            {
                ok[i]=1;
                fm[i]=j;
                break;
            }
        }
    }
    if(!ok[n])
    {
        cout<<"NO"<<endl;
        return 0;
    }
    vector<ll> ans;
    int i=n;
    while(i>0)
    {
        ans.pb(i);
        i=fm[i];
    }
    sort(ans.begin(),ans.end());
    cout<<"YES"<<endl;
    cout<<ans.size()<<endl;
    for(int k=0;k<ans.size();k++)
    {
        cout<<fm[ans[k]]+1<<" "<<ans[k]<<endl;
    }


}