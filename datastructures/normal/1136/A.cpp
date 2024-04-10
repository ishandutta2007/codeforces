#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#define int long long
using namespace std;
int n,l[10005],r[10005],a,ans;
signed main(){
    cin>>n;
    for (int i=1;i<=n;i++)cin>>l[i]>>r[i];
    cin>>a;
    for (int i=1;i<=n;i++)
        if (r[i]>=a)ans++;
    cout<<ans<<endl;
    return 0;
}