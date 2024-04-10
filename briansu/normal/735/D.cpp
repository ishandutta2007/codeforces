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

bool ck(ll n)
{
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)return 0;
    }
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    ll n;
    cin>>n;
    if(ck(n))cout<<1<<endl;
    else if(n%2==0)cout<<2<<endl;
    else if(ck(n-2))cout<<2<<endl;
    else cout<<3<<endl;


}