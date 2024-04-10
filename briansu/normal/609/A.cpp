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
    ll n,m;
    cin>>n>>m;
    vector<ll> d;
    d.resize(n);
    for(int i=0;i<n;i++)
    {
        cin>>d[i];
    }
    sort(d.begin(),d.end());
    int cnt=0;
    while(m>0)
    {
        m-=d.back();
        cnt++;
        d.pop_back();
    }
    cout<<cnt<<endl;

}