#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <unordered_map>
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=1;i<=n;++i)
using namespace std;
int n;
map<int,long long> dic;
long long a[510000];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){ scanf("%lld",&a[i]); a[i]-=i; dic[a[i]]+=a[i]+i; }
    long long ans=0;
    for(auto p:dic)ans=max(ans,p.second);
    cout<<ans<<endl;
    return 0;
}