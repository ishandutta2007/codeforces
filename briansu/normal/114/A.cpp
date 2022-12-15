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
    ll k,l;
    cin>>k>>l;
    ll cnt=-1;
    while(l>1)
    {
        if(l%k==0)
        {
            l/=k;
            cnt++;
        }
        else
        {
            cout<<"NO\n";
            return 0;
        }
    }
    cout<<"YES\n"<<cnt<<endl;

}