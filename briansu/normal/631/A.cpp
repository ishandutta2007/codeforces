#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
const double EPS=1e-4;
const ll INF=ll(1e18);
const int sINF=int(1e9);
typedef pair<int,int> ii;
typedef map<int,int>::iterator mpit;
typedef long long ll;
using namespace std;

ll n;
int main()
{

    cin>>n;
    ll a=0,b=0;
    for(int i=0;i<n;i++)
    {
        int tmp;
        cin>>tmp;
        a=a|tmp;
    }
    for(int i=0;i<n;i++)
    {
        int tmp;
        cin>>tmp;
        b=b|tmp;
    }
    cout<<a+b<<endl;
}