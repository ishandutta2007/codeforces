#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <cmath>
#define rep(i,n) for(int i=1;i<=n;++i)
#define mp make_pair
#define pb push_back
using namespace std;
int main()
{
    long long a,b,c,d;
    cin>>a>>b>>c>>d;
    if (a>b)swap(a,b);
    if (a>c)swap(a,c);
    if (b>c)swap(b,c);
    long long ans1=max(0ll,d-(b-a))+max(0ll,2*d-(c-a))+max(0ll,d-(c-b));
    long long ans2=max(0ll,d-(b-a))+max(0ll,d-(c-b));
    long long ans3=max(0ll,2*d-(c-a))+max(0ll,d-(c-b))+max(0ll,d-(b-a));
    cout<<min(ans1,min(ans2,ans3))<<endl;
    return 0;
}