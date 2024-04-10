#include <bits/stdc++.h>

using namespace std;
#define rep(i,n) for (long long i = 0, _n = (n); i < _n; i++)
#define ll long long
#define pb push_back
#define mp make_pair

#define PI 3.1415926535897932385
#define INF 1000111222
#define EPS 1e-7
#define MAXN 100000
#define MOD 1000000007
#define dec decr
//END OF COMPETITVE PROGRAMMING TEMPLATE

int main () 
{
	ios_base::sync_with_stdio(false);
            cin.tie(NULL);
	    #ifndef ONLINE_JUDGE
  	    freopen("input.txt", "r", stdin);
   	    freopen("output.txt", "w", stdout);
   	    #endif
            ll n,k;
            cin>>n>>k;
            set<ll> s;
            ll ar[n+1]={0};
            rep(i,k)
            {
                ll x;
                cin>>x;
                ar[x]++;
                s.insert(x);
                if(s.size()==n)
                {
                    cout<<"1";
                    s.clear();
                    rep(j,n)
                    {
                        ar[j+1]--;
                        if(ar[j+1]>0)
                        {
                            s.insert(j+1);
                        }
                    }
                }
                else
                {
                    cout<<"0";
                }
            }
            return 0;
}