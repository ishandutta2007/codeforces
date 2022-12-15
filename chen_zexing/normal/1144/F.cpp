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
int color[200005];
vector <int> v[200005];
int dfs(int x){
    int f=1;
    for(auto t:v[x]){
        if(color[t]==-1) color[t]=3-color[x],f&=dfs(t);
        else if(color[t]==color[x]) return 0;
    }
    return f;
}
int x[200005],y[200005];
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=m;i++) scanf("%d%d",&x[i],&y[i]),v[x[i]].push_back(y[i]),v[y[i]].push_back(x[i]);
        memset(color,-1,sizeof(color));
        color[1]=1;
        if(!dfs(1)){
            puts("NO");
            continue;
        }
        puts("YES");
        for(int i=1;i<=m;i++){
            if(color[x[i]]==1) printf("1");
            else printf("0");
        }
    }
    return 0;
}
//
/// 
//01
//