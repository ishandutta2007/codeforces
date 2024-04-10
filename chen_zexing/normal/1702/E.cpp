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
#include <random>
using namespace std;
vector <int> pos[200005],v[200005];
int c[200005],flag=1;
void dfs(int x){
    for(auto t:v[x]){
        if(c[t]&&c[t]!=3-c[x]) flag=0;
        else if(!c[t]) c[t]=3-c[x],dfs(t);
    }
}
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) pos[i].clear(),v[i].clear(),c[i]=0;
        for(int i=1,x,y;i<=n;i++){
            scanf("%d%d",&x,&y);
            pos[x].push_back(i),pos[y].push_back(i);
        }
        int f=1;
        for(int i=1;i<=n;i++) if(pos[i].size()!=2) f=0;
        if(!f){
            puts("NO");
            continue;
        }
        for(int i=1;i<=n;i++) v[pos[i][0]].push_back(pos[i][1]),v[pos[i][1]].push_back(pos[i][0]);
        flag=1;
        for(int i=1;i<=n;i++) if(!c[i]) c[i]=1,dfs(i);
        puts(flag?"YES":"NO");
    }
    return 0;
}
//unordered_map