#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
const double EPS=(1e-4);
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
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,k;
    cin>>n>>k;
    int now,tg;
    bool d[n];
    cin.ignore(1);
    for(int i=0;i<n;i++)
    {
        char tmp;
        cin>>tmp;
        if(tmp=='G')
        {
            now=i;
            d[i]=false;
        }
        else if(tmp=='T')
        {
            tg=i;
            d[i]=false;
        }
        else d[i]=(tmp=='#');
    }
    if(now>tg)swap(now,tg);
    while(1)
    {
        now+=k;
        if(now>tg)
        {
            cout<<"NO\n";
            return 0;
        }
        if(now==tg)
        {
            cout<<"YES\n";
            return 0;
        }
        if(d[now])
        {
            cout<<"NO\n";
            return 0;
        }
    }


}