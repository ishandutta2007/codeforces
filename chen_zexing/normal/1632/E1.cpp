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
using namespace std;
vector <int> v[300005];
int d[300005][2],dep[300005],dis[300005],f[300005];
void dfs(int x,int from){
    dep[x]=dep[from]+1,d[x][0]=dep[x],f[dep[x]-1]=1;
    for(auto t:v[x]) if(t!=from){
            dfs(t,x);
            if(d[t][0]>d[x][0]) d[x][1]=d[x][0],d[x][0]=d[t][0];
            else if(d[t][0]>d[x][1]) d[x][1]=d[t][0];
        }
    if(d[x][1]) dis[d[x][1]-1]=max(dis[d[x][1]-1],d[x][0]+d[x][1]-dep[x]*2);
}
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n;
        cin>>n;
        for(int i=1;i<=n+1;i++) v[i].clear(),d[i][0]=d[i][1]=0,dis[i]=0,f[i]=0;
        for(int i=1,x,y;i<n;i++) scanf("%d%d",&x,&y),v[x].push_back(y),v[y].push_back(x);
        dfs(1,0);
        for(int i=n-1;i>=0;i--) dis[i]=max(dis[i],dis[i+1]),f[i]=max(f[i],f[i+1]);
        for(int i=1,now=1;i<=n;i++){
            while(f[now+1]&&(dis[now+1]+1)/2+i>now) now++;
            printf("%d ",now);
        }
        puts("");
    }
    return 0;
}
//unordered_map