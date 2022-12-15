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
using namespace std;
vector <int> v[100005];
int d[100005],x[100005],y[100005];
int dep[100005],vv[100005];
void dfs(int x,int from){
    if(from) vv[x]=7-vv[from];
    dep[x]=dep[from]+1;
    for(auto t:v[x]) if(t!=from) dfs(t,x);
}
int main() {
    int T = 1;
    cin >> T;
    while(T--) {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) v[i].clear(),d[i]=0;
        for(int i=1;i<n;i++) scanf("%d%d",&x[i],&y[i]),v[x[i]].push_back(y[i]),v[y[i]].push_back(x[i]),d[x[i]]++,d[y[i]]++;
        int f=0;
        for(int i=1;i<=n;i++) if(d[i]>2) f=1;
        if(f){
            puts("-1");
            continue;
        }
        for(int i=1;i<=n;i++)
            if(d[i]==1){
                vv[i]=2;
                dfs(i,0);
                break;
            }
        for(int i=1;i<n;i++){
            if(dep[x[i]]<dep[y[i]]) swap(x[i],y[i]);
            printf("%d ",vv[x[i]]);
        }
        puts("");
    }
    return 0;
}