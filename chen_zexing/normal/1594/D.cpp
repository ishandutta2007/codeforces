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
struct edge{
    int ed,w;
};
vector <edge> v[200005];
char s[25];
int c[200005],vis[200005];
int dfs(int x){
    int f=1;
    for(auto t:v[x]){
        if(c[t.ed]!=-1){
            if((c[t.ed]^t.w)!=c[x]) f=0;
        }
        else c[t.ed]=c[x]^t.w,f&=dfs(t.ed);
    }
    return f;
}
pair <int,int> count(int x){
    int tot=1,fst=c[x]==1;
    vis[x]=1;
    for(auto t:v[x]){
        if(vis[t.ed]) continue;
        auto temp=count(t.ed);
        tot+=temp.first,fst+=temp.second;
    }
    return make_pair(tot,fst);
};
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n,m,f=1;
        cin>>n>>m;
        for(int i=1;i<=n;i++) v[i].clear(),c[i]=-1,vis[i]=0;
        for(int i=1,x,y;i<=m;i++){
            scanf("%d%d",&x,&y);
            scanf("%s",s);
            if(s[0]=='i') v[x].push_back(edge{y,1}),v[y].push_back(edge{x,1});
            else v[x].push_back(edge{y,0}),v[y].push_back(edge{x,0});
        }
        for(int i=1;i<=n;i++) if(c[i]==-1){
                c[i]=1;
                int temp=dfs(i);
                if(!temp){
                    puts("-1");
                    f=0;
                    break;
                }
            }
        if(!f) continue;
        int ans=0;
        for(int i=1;i<=n;i++)
            if(!vis[i]){
                auto temp=count(i);
                ans+=max(temp.second,temp.first-temp.second);
            }
        printf("%d\n",ans);
    }
    return 0;
}
//
/// 
//01
//