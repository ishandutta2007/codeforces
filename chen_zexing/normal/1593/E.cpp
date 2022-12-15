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
vector <int> v[400005];
int vis[400005],d[400005];
int main() {
    int T = 1;
    cin >> T;
    while(T--){
        int n,k;
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++) v[i].clear(),vis[i]=0,d[i]=0;
        for(int i=1,x,y;i<n;i++) scanf("%d%d",&x,&y),v[x].push_back(y),v[y].push_back(x),d[x]++,d[y]++;
        queue <int> now,nxt;
        int cnt=n;
        for(int i=1;i<=n;i++) if(d[i]<=1) now.push(i);
        for(int i=1;i<=k;i++){
            if(!cnt) break;
            while(!now.empty()){
                int temp=now.front();
                now.pop();
                vis[temp]=1,cnt--;
                for(auto t:v[temp]) if(!vis[t]){
                        d[t]--;
                        if(d[t]==1) nxt.push(t);
                    }
            }
            swap(nxt,now);
        }
        printf("%d\n",cnt);
    }
    return 0;
}
//
/// 
//01
//