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
    int d[10]={2,7,2,3,3,4,2,5,1,2};
    int n;
    cin>>n;
    int a=n/10,b=n%10;
    cout<<d[a]*d[b]<<endl;

}