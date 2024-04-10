#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file  
#include <ext/pb_ds/tree_policy.hpp>  
#include <functional> // for less  
#include <iostream>  
using namespace std;
#define ll long long

#define rep(i,n) for (long long i = 0, _n = (n); i < _n; i++)
#define debug(x) cout<<#x<<": "<<x<<endl
#define ld long double
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
auto clk=clock();
#define setb __builtin_popcount
#define PI 3.1415926535897932385
#define INF 10000000000000ll
#define EPS 1e-7
#define MAXN 100000
#define MOD 1000000007
#define endl '\n'
#define dec decr
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// ll gcd(ll a, ll b) 
// { 
//     if (a == 0) 
//         return b; 
//     return gcd(b % a, a); 
// } 
// ll modexp(ll x, ll y, ll p)
// {
//     ll res = 1;   
//     x = x % p;  
//     while (y > 0)
//     {
//         if (y %2==1)    
//             res = (res*x) % p;
//         y = y>>1;     
//         x = (x*x) % p; 
//     }
//     return res;
// }
ll ar[300007]={0};
ll pos[300007]={0};
vector<pair<ll,ll>>v;
void swa(ll x,ll y)
{
    if(x!=y)
    {
        v.pb(mp(x,y));
        swap(ar[x],ar[y]);
        swap(pos[ar[x]],pos[ar[y]]);
    }
}
int main () 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<fixed;
    cout<<setprecision(9);
     #ifdef rg
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif  
    ll n;
    cin>>n;
    rep(i,n)
    {
        cin>>ar[i+1];
        pos[ar[i+1]]=i+1;
    }
    if(pos[1]!=1)
    {
        if(pos[1]<=n/2)
        {
            swa(n,pos[1]);
            swa(n,1);
        }
        else
        {
            swa(pos[1],1);
        }
    }
    for(ll i=2;i<n;i++)
    {
        if(pos[i]!=i)
        {
            if(i<=n/2)
            {
                if(pos[i]<=n/2)
                {
                    swa(n,pos[i]);
                    swa(i,n);
                }
                else
                {
                    if(pos[i]!=n)
                    {
                        ll z=pos[i];
                        swa(pos[i],1);
                        swa(1,n);
                        swa(z,1);
                    }
                    swa(n,i);
                }
            }
            else
            {
                ll z=pos[i];
                swa(1,z);
                swa(1,i);
                swa(1,z);
            }
        }
    }
    cout<<v.size()<<endl;
    for(auto x:v)
    {
        cout<<x.ff<<' '<<x.ss<<endl;
    }



    #ifdef rg
    cout<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
    #endif
    return 0;
}