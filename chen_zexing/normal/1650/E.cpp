#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <climits>
#include <algorithm>
#include <complex>
#include <string.h>
#include <iomanip>
#include <assert.h>
using namespace std;
multiset <int> s;
int a[200005];
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n,d,mx=0;
        cin>>n>>d,a[0]=0;
        s.clear();
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),s.insert(a[i]-a[i-1]-1);
        for(int i=1;i<n;i++){
            s.erase(s.find(a[i]-a[i-1]-1)),s.erase(s.find(a[i+1]-a[i]-1));
            s.insert(a[i+1]-a[i-1]-1);
            auto it=s.end();
            --it;
            int v=*it,dis=max((v-1)/2,d-a[n]-1);
            mx=max(mx,min(dis,*s.begin()));
            s.erase(s.find(a[i+1]-a[i-1]-1));
            s.insert(a[i]-a[i-1]-1),s.insert(a[i+1]-a[i]-1);
        }
        s.erase(s.find(a[n]-a[n-1]-1));
        auto it=s.end();
        --it;
        int v=*it,dis=max((v-1)/2,d-a[n-1]-1);
        mx=max(mx,min(dis,*s.begin()));
        printf("%d\n",mx);
    }
    return 0;
}
//unordered_map