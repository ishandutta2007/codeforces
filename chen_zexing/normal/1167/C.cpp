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
int fa[500005],sz[500005];
int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++) fa[i]=i,sz[i]=1;
        for(int i=1,k,st;i<=m;i++){
            scanf("%d",&k);
            if(k) scanf("%d",&st);
            for(int j=2,t;j<=k;j++){
                scanf("%d",&t);
                t=find(t),st=find(st);
                if(t!=st) fa[t]=st,sz[st]+=sz[t];
            }
        }
        for(int i=1;i<=n;i++) printf("%d ",sz[find(i)]);
    }
    return 0;
}
//
/// 
//01
//