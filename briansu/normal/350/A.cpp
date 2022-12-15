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
    int n,m;
    cin>>n>>m;
    int w=100,rt=0,rf=100;
    for(int i=0;i<n;i++)
    {
        int tmp;
        cin>>tmp;
        rt=max(rt,tmp);
        rf=min(rf,tmp);
    }
    for(int i=0;i<m;i++)
    {
        int tmp;
        cin>>tmp;
        w=min(w,tmp);
    }
    rt=max(rf*2,rt);
    if(rt<w)cout<<rt<<endl;
    else cout<<-1<<endl;
}