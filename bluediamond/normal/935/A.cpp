///#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <math.h>
#include <set>
#include <vector>
#include <iomanip>
#include <bitset>
#include <queue>
using namespace std;
#define ll long long
ll n,ans=0;
int main()
{
    cin>>n;
    for(ll x=1;x+x*1<=n;x++)
        if(n%x==0 and n/x>=0)
            ans++;
    cout<<ans;
    return 0;
}
/**

**/