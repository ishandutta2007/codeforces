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
vector <int> v[1000005];
int a[1000005],vis[1000005],ans[1000005];
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n,d;
        cin>>n>>d;
        for(int i=0;i<n;i++) v[i].clear(),vis[i]=0;
        for(int i=0;i<n;i++) scanf("%d",&a[i]),v[i].push_back((i+d)%n);
        queue <int> q;
        for(int i=0;i<n;i++) if(a[i]==0) ans[i]=0,vis[i]=1,q.push(i);
        while(!q.empty()){
            int temp=q.front();
            q.pop();
            for(auto t:v[temp]) if(!vis[t]) vis[t]=1,q.push(t),ans[t]=ans[temp]+1;
        }
        int fl=1;
        for(int i=0;i<n;i++) if(!vis[i]) fl=0;
        if(!fl){
            puts("-1");
            continue;
        }
        int mx=0;
        for(int i=0;i<n;i++) mx=max(mx,ans[i]);
        printf("%d\n",mx);
    }
    return 0;
}
//
/// 
//01
//