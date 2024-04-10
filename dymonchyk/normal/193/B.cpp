#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

int cnt=0,n,u,r;
vector <int> b,k,p;
long long ans;

void go(int v[32],int left) {
    if (left%2==0) {
        long long cur=0;
        for(int i=0;i<n;++i)
            cur+=1LL*v[i]*k[i];
        ans=max(ans,cur);
    } else {
        long long cur=0;
        for(int i=0;i<n;++i) {
            cur+=1LL*k[i]*(v[i]^b[i]);
        }
        ans=max(ans,cur);
    }
    cnt++;
    if (left==0) return;
    int v1[32]={0},v2[32]={0},v3[32]={0};
    for(int i=0;i<n;++i)
        v1[i]=v[p[i]-1]+r;
    go(v1,left-1);
    if (left>1) {
        for(int i=0;i<n;++i)
            v2[i]=v[i]^b[i];
        for(int i=0;i<n;++i)
            v3[i]=v2[p[i]-1]+r;
        go(v3,left-2);
    }
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    cin >> n >> u >> r;
    int a[32];
    b.resize(n); k.resize(n); p.resize(n);
    ans=1000000000; ans*=-ans;
    for(int i=0;i<n;++i)
        cin >> a[i];
    for(int i=0;i<n;++i)
        cin >> b[i];
    for(int i=0;i<n;++i)
        cin >> k[i];
    for(int i=0;i<n;++i)
        cin >> p[i];
    go(a,u);
    cout << ans << endl;
//  cout << clock() << endl;
    return 0;
}