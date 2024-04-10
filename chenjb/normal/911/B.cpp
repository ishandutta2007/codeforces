#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
#include <utility>
#include <bitset>
using namespace std;
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
int n;
int a,b;
int main()
{
    cin>>n>>a>>b;
    int ans=0;
    for(int i=1;i<n;i++)ans=max(ans,min(a/i,b/(n-i)));
    cout<<ans<<endl;
}