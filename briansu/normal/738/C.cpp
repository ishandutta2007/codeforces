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
typedef long long ll;
using namespace std;

ll lb=0,ub=ll(sINF)*10;
vector<ll> gas;
vector<ii> d;
ll n,k,s,t;
bool test(ll now)
{
    ll pos=0;
    ll tt=0;
    for(int i=0;i<=k;i++)
    {
        ll tmp=now-(gas[i]-pos);
        if(tmp<0)return 0;
        tmp=min(tmp,gas[i]-pos);
        tt+=2*(gas[i]-pos)-tmp;
        pos=gas[i];
    }
    if(tt>t)return 0;
    else return 1;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    cin>>n>>k>>s>>t;
    d.resize(n);
    gas.resize(k);
    for(int i=0;i<n;i++)cin>>d[i].second>>d[i].first;
    for(int i=0;i<k;i++)cin>>gas[i];
    gas.push_back(s);
    sort(gas.begin(),gas.end());
    while(ub-1!=lb)
    {
        ll mid=(ub+lb)/2;
        //cout<<mid<<" "<<test(mid)<<endl;
        if(test(mid))ub=mid;
        else lb=mid;
    }
    sort(d.begin(),d.end());
    vector<ii>::iterator it=lower_bound(d.begin(),d.end(),ii(ub,-1));
    if(it==d.end())
    {
        cout<<"-1\n";
        return 0;
    }
    ll mn=INF;
    for(;it!=d.end();it++)
    {
        mn=min(mn,(*it).second);
    }
    cout<<mn<<endl;

}