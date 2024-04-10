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

ll n,m,a;
int main()
{

    cin>>n>>m>>a;
    n=ceil(n/(a*1.0));
    m=ceil(m/(a*1.0));
    cout<<n*m<<endl;

}