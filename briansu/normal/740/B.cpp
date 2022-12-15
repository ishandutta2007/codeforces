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
    int d[n];
    for(int i=0;i<n;i++)cin>>d[i];
    ll tt=0;
    for(int i=0;i<m;i++)
    {
        int l,r;
        cin>>l>>r;
        l--;
        ll tmp=0;
        for(int j=l;j<r;j++)tmp+=d[j];
        if(tmp>0)tt+=tmp;
    }
    cout<<tt<<endl;
}