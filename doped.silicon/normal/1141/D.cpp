#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (long long i = 0, _n = (n); i < _n; i++)
#define debug(x) cout<<#x<<": "<<x<<endl
/*Author Ritick Goenka || ritick(codechef) ||doped.silicon(codeforces) */
/*IIT Roorkee = <3 */
#define ll long long
#define int long long

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
        string l,r;
        cin>>l>>r;
        vector<ll>le[27];
        vector<ll>ri[27];
        rep(i,n)
        {
            if(l[i]=='?')
            {
                le[26].pb(i+1);
            }
            else
            {
                le[l[i]-'a'].pb(i+1);
            }
            if(r[i]=='?')
            {
                ri[26].pb(i+1);
            }
            else
            {
                ri[r[i]-'a'].pb(i+1);
            }
        }
        ll ans=0,a=0,b=0;
        rep(i,26)
        {
            ll x=le[i].size();
            ll y=ri[i].size();
            if(le[i].size()>ri[i].size())
            {
                ans+=ri[i].size();
                a+=x-y;
            }
            else
            {
                ans+=x;
                b+=y-x;
            }
            // debug(ans);
        }
        ll x1=le[26].size();
            ll y1=ri[26].size();
        ll z1=min(a,y1);
        ll z2=min(b,x1);
        ans+=z1+z2;
        ll k=min(ri[26].size()-z1,le[26].size()-z2);
        ans+=k;
        ll ii=0,jj=0;
        cout<<ans<<endl;
        rep(i,26)
        {
            ll x=le[i].size();
            ll y=ri[i].size();
            ll i1=0,j1=0;
            ll zz=min(x,y);
            // debug(i);
            // debug(zz);
            while(zz--)
            {
                cout<<le[i][i1]<<" "<<ri[i][j1]<<endl;
                i1++;
                j1++;
            }
            // debug(i1);
            // debug(j1);
            // debug(x);
            // // debug(z1);
            // debug(y);
            while(i1<x&&(z1)>0)
            {
                cout<<le[i][i1]<<" "<<ri[26][ii]<<endl;
                ii++;
                i1++;
                z1--;
            }
            while(j1<y&&(z2)>0)
            {
                cout<<le[26][jj]<<" "<<ri[i][j1]<<endl;
                jj++;
                j1++;
                z2--;
            }
        }
        while(k--)
        {
            cout<<le[26][ii]<<" "<<ri[26][jj]<<endl;
            ii++;
            jj++;
        }




            return 0;

}