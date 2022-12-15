#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
const double EPS=1e-8;
const ll INF=ll(1e18);
typedef pair<int,ll> ill;
int main()
{
    int a[3];
    for(int i=0;i<3;i++)cin>>a[i];
    int most=0;
    for(int i=0;i<3;i++)if(a[i]>most)most=a[i];
    int sec=0;
    for(int i=0;i<3;i++)if(a[i]>sec&&a[i]!=most)sec=a[i];
    int sum=0;
    for(int i=0;i<3;i++)sum+=abs(a[i]-sec);
    cout<<sum<<endl;
}