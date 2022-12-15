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
int a[300005],pos[300005],cnt[300005];
vector <int> v[300005];
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n,m,ans=0,nd=0;
        cin>>n>>m;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),pos[a[i]]=i;
        for(int i=1,x,y;i<=m;i++){
            scanf("%d%d",&x,&y);
            if(pos[y]>pos[x]) cnt[x]++,v[y].push_back(x);
        }
        for(int i=n-1;i>=1;i--) if(cnt[a[i]]>=n-i-nd){
                ans++,nd++;
                for(auto x:v[a[i]]) cnt[x]--;
            }
        printf("%d\n",ans);
    }
    return 0;
}
//
/// 
//01
//