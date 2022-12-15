#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <assert.h>
#include <algorithm>
#include <stdlib.h>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <time.h>
#include <map>
#include <stack>
#include <unordered_set>
#include <bitset>
#define hash hassh
#define li __int128_t
#define ull unsigned long long
using namespace std;
multiset <int> s;
struct node{
    int t,b;
    friend bool operator <(node a,node b){
        return a.b>b.b;
    }
}a[300005];
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n,k;
        cin>>n>>k;
        for(int i=1;i<=n;i++) scanf("%d%d",&a[i].t,&a[i].b);
        sort(a+1,a+n+1);
        long long ans=0,temp=0;
        for(int i=1;i<=n;i++){
            s.insert(a[i].t),temp+=a[i].t;
            if(s.size()>k) temp-=*s.begin(),s.erase(s.begin());
            ans=max(ans,temp*a[i].b);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
//
/// 
//01
//