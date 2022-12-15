#include <bits/stdc++.h>
#include <windows.h>
#include<time.h>
using namespace std;
typedef long long ll;
typedef double lf;
const double EPS=(1e-6);
const ll INF=ll(1e18);
const int sINF=int(1e8);
typedef pair<ll,ll> ii;
typedef pair<string,int> si;
typedef map<int,int>::iterator mpit;
typedef long long ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,m;
    cin>>n>>m;
    ll mn=INF;
    for(ll i=0;i<m;i++)
    {
        ll l,r;
        cin>>l>>r;
        mn=min(mn,r-l+1);
    }
    cout<<mn<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<(i==0?"":" ")<<i%mn;
    }
    cout<<endl;
}