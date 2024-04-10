#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
struct fint
{
    ll a,b;
};
bool cmp(fint x,fint y)
{
    return x.b>y.b;
}
fint v[100005];
ll n,s;
int main()
{
    cin>>n;
    for(ll i=1;i<=n;i++)
    {
        cin>>v[i].a;
        s+=v[i].a;
    }
    for(int i=1;i<=n;i++)
        cin>>v[i].b;
    sort(v+1,v+n+1,cmp);
    if(s<=v[1].b+v[2].b)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}