#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef double lf;
const double EPS=1e-4;
const ll INF=ll(1e18);
const int sINF=int(1e8);
typedef pair<int,int> ii;
typedef set<int>::iterator isit;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    ll n;
    char c;
    cin>>n>>c;

    map<char,int> m;
    m['f']=1;
    m['e']=2;
    m['d']=3;
    m['a']=4;
    m['b']=5;
    m['c']=6;
    ll ans;
    if(n%4==1||n%4==2)
    {
        ans=(n-1)+(n/2)*6+m[c];
    }
    else
    {
        ans=(n-3)+((n-2)/2)*6+m[c];
    }
    cout<<ans<<endl;
}