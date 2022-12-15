#include <stdio.h>
#include<iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <map>
#include <stack>
#include <unordered_set>
#define hash hassh
using namespace std;
vector <int> v[200005];
int cnt[200005],c,f[200005];
void dfs(int x,int from){
    if(f[x]) return;
    cnt[x]++;
    if(cnt[x]>1){
        f[x]=1;
        return;
    }
    for(int i=0;i<v[x].size();i++)
        if(v[x][i]!=from) {
            dfs(v[x][i],x);
            if(f[v[x][i]]==1){
                f[x]++;
            }
        }
}
void cal(int x,int from){
    c++;
    for(int i=0;i<v[x].size();i++)
        if(!f[v[x][i]]&&v[x][i]!=from)
            cal(v[x][i],x);
}
int main() {
    int T;
    cin>>T;
    while(T--){
        long long ans=0;
        int n,x,y;
        scanf("%d",&n);
        ans=1LL*n*(n-1);
        for(int i=1;i<=n;i++) v[i].clear(),cnt[i]=0,f[i]=0;
        for(int i=1;i<=n;i++){
            scanf("%d%d",&x,&y);
            v[x].push_back(y);
            v[y].push_back(x);
        }
        dfs(1,0);
        //for(int i=1;i<=n;i++) cout<<f[i]<<endl;
        for(int i=1;i<=n;i++){
            if(f[i]){
                c=0;
                cal(i,0);
                ans-=1LL*(c-1)*c/2;
                //cout<<i<<" "<<c<<" "<<ans<<endl;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}