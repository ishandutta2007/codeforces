#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
const double EPS=(1e-6);
const ll INF=ll(1e18);
const int sINF=int(1e9);
typedef pair<ll,ll> ii;
typedef pair<ii,int> iii;
typedef map<int,int>::iterator mpit;
typedef multiset<int>::iterator stit;
typedef long long ll;
using namespace std;


int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);
    ll n,a,b;
    cin>>n>>a>>b;
    if(a>b)swap(a,b);
    ll d[n];
    for(ll i=0;i<n;i++)cin>>d[i];
    sort(d,d+n,greater<ll>());
    double tmp=0,tmp2=0;
    for(ll i=0;i<a;i++)tmp+=d[i];
    for(ll i=a;i<a+b;i++)tmp2+=d[i];
    printf("%.9f",tmp/lf(a)+tmp2/lf(b));

}