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

ll a[3];
int main()
{
    cin>>a[0]>>a[1];
    a[2]=a[1]+a[0];
    for(int k=0;k<3;k++)
    {
    ll tmp=0;
    while(a[k]!=0)
    {
        tmp*=10;tmp+=a[k]%10;
        a[k]/=10;
    }
    a[k]=0;
    while(tmp!=0)
    {
        if(tmp%10==0)tmp/=10;
        else{
            a[k]*=10;
            a[k]+=tmp%10;
            tmp/=10;
        }
    }
    }
    if(a[2]==a[1]+a[0])cout<<"YES\n";
    else cout<<"NO\n";


}