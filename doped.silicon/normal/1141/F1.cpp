#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (long long i = 0, _n = (n); i < _n; i++)
#define debug(x) cout<<#x<<": "<<x<<endl
/*Author Ritick Goenka || ritick(codechef) ||doped.silicon(codeforces) */
/*IIT Roorkee = <3 */
#define ll long long

#define ld double
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define INF 1000000000000000
#define MOD 1000000007
signed main () 
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout<<setprecision(11);
        #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        #endif
        ll n;
        cin>>n;
        ll ar[n];
        rep(i,n)
        {
            cin>>ar[i];
        }
        ll sum[n+1]={0};
        rep(i,n)
        {
            sum[i+1]=sum[i]+ar[i];
        }
        set<int>s;
        rep(i,n)
        {
            for(ll j=i;j<n;j++)
            {
                ll x=sum[j+1]-sum[i];
                s.insert(x);
            }
        }
        ll ans=0;
        ll x1=0;
        map<ll,ll>m1;
        ll i=0;
        for(auto z:s)
        {
            i=0;
            ll last=-1,p2=0,su=0;
            ll t=0;
            // debug(z);
            m1[0]=0;
            while(i<n)
            {
                ll x=sum[i+1]-z;
                if(m1.find(x)!=m1.end()&&(m1.find(x)->second)>=last)
                {
                    t++;
                    last=i+1;
                }
                if(t>x1)
                {
                    x1=t;
                    ans=z;
                    // debug(z);
                    // debug(t);
                }
                m1[sum[i+1]]=i+1;
                i++;

            }
            m1.clear();
        }
            cout<<x1<<endl;
            ll z=ans;
            ll last=-1,p2=0,su=0;
            ll t=0;
            // z=3;
            // debug(z);
            i=0;
            m1[0]=0;
            while(i<n)
            {
                ll x=sum[i+1]-z;
                // debug(x);
                if(m1.find(x)!=m1.end()&&(m1.find(x)->second)>=last)
                {
                    t++;
                    ll kk=m1.find(x)->second;
                    last=i+1;
                    cout<<kk+1<<" "<<i+1<<endl;
                }
                m1[sum[i+1]]=i+1;
                i++;
            }
            m1.clear();
            



            return 0;

}