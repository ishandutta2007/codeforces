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
int a[200005],d[200005],t[200005];
int lst[200005],rest[200005];
set <int> s[400005];
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=m;i++) scanf("%d%d",&d[i],&t[i]);
        int l=1,r=4e5;
        while(l<r){
            int mid=(l+r)>>1;
            for(int i=1;i<=n;i++) lst[i]=0,s[i].clear(),rest[i]=a[i];
            for(int i=1;i<=m;i++) if(d[i]<=mid){
                    if(d[i]>lst[t[i]]){
                        if(lst[t[i]]) s[lst[t[i]]].erase(s[lst[t[i]]].find(t[i]));
                        s[d[i]].insert(t[i]),lst[t[i]]=d[i];
                    }
                }
            int tot=0,ac=0;
            for(int i=1;i<=mid;i++){
                tot++;
                for(auto it=s[i].begin();it!=s[i].end();++it) {
                    if (rest[*it]) {
                        int temp = min(rest[*it], tot);
                        rest[*it] -= temp, tot -= temp;
                    }
                }
            }
            int sum=0;
            for(int i=1;i<=n;i++) sum+=rest[i];
            if(tot>=sum*2) r=mid;
            else l=mid+1;
        }
        cout<<l<<endl;
    }
    return 0;
}
//
/// 
//01
//