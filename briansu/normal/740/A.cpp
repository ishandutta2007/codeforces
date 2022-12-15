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
    ll n,a,b,c;
    cin>>n>>a>>b>>c;
    n%=4;
    if(n==0)
    {
        cout<<0<<endl;
        return 0;
    }
    ll mn=INF;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<2;j++)
        {
            for(int k=0;k<4;k++)
            {
                if((i+2*j+3*k+n)%4==0)mn=min(mn,i*a+j*b+k*c);
            }
        }
    }
    cout<<mn<<endl;
}