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

vector<ll> pos;
ll n,a,b,k,bts=0;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    cin>>n>>a>>b>>k;
    pos.push_back(-1);
    cin.ignore(1);
    for(ll i=0;i<n;i++)
    {
        char c;
        cin>>c;
        if(c=='1')pos.push_back(i);
    }
    pos.push_back(n);
    for(ll i=1;i<=k+1;i++)
    {
        if(pos[i]-pos[i-1]-1>=b)bts+=(pos[i]-pos[i-1]-1)/b;
    }
    cout<<bts-a+1<<endl;
    k++;
    while(bts>=a)
    {
        if(pos[k]-pos[k-1]<=b)
        {
            pos.pop_back();
            k--;
        }
        else
        {
            pos[k]-=b;
            cout<<pos[k]+1<<" ";
            bts--;
        }
    }
    cout<<endl;
}