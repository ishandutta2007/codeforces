#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double EPS=1e-3;
const ll INF=ll(1e18);
struct ii
{
    int first;
    int second;
    ii(int a,int b){this->first=a;this->second=b;}
};
int main()
{
    ll a,b,c,d,e;
    cin>>a>>b>>c>>d>>e;
    a=(c>a?c:a);//start
    b=(d<b?d:b);//end
    if(a>b)cout<<0<<endl;
    else if(e<=b&&e>=a)cout<<b-a<<endl;
    else cout<<b-a+1<<endl;

}