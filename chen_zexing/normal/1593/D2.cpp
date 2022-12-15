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
#include <list>
#define hash hassh
#define li __int128_t
#define ull unsigned long long
using namespace std;
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}
int a[45];
set <pair<int,int>> s[45];
int main() {
    int T = 1;
    cin >> T;
    while(T--){
        int n,ans=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),s[i].clear();
        if(n==2){
            puts("-1");
            continue;
        }
        sort(a+1,a+n+1);
        s[1].insert(make_pair(0,0));
        s[1].insert(make_pair(1,0));
        for(int i=2;i<=n;i++)
            for(int j=1;j<i;j++){
                for(auto it=s[j].begin();it!=s[j].end();++it){
                    int cnt=(*it).first,g=(*it).second;
                    g=cnt?gcd(g,a[i]-a[j]):0,cnt++;
                    if(cnt==n/2){
                        if(g) ans=max(ans,g);
                        else ans=INT_MAX;
                    }
                    else s[i].insert(make_pair(cnt,g));
                }
            }
        if(ans==INT_MAX) puts("-1");
        else printf("%d\n",ans);
    }
    return 0;
}
//
/// 
//01
//