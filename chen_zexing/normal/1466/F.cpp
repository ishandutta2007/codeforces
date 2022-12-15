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
vector <int> v[500005];
unordered_map <int,int> mp;
vector <int> ans;
long long cnt=1,mod=1000000007;
int fl[500005];
int c[500005];
int fa[500005];
int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main() {
    int n,m,x=0;
    cin>>n>>m;
    for(int i=1;i<=m;i++) fa[i]=i;
    for(int i=1;i<=n;i++){
        int t,tt;
        scanf("%d",&t);
        for(int j=1;j<=t;j++){
            scanf("%d",&tt);
            v[i].push_back(tt);
        }
    }
    for(int i=1;i<=n;i++){
        int f=0;
        if(v[i].size()==1){
            int t=v[i][0];
            t=find(t);
            if(!fl[t]){
                f=1;
                fl[t]=1;
            }
        }
        else{
            int x=v[i][1],y=v[i][0];
            if(x>y) swap(x,y);
            x=find(x),y=find(y);
            if(x==y){
                continue;
            }
            else {
                fa[y] = x;
                if (fl[x] && fl[y]) continue;
                if (fl[x] || fl[y]) fl[x] = 1, f = 1;
                else f = 1;
            }
        }
        if(f) cnt=cnt*2%mod,ans.push_back(i);
    }
    printf("%lld %d\n",cnt,ans.size());
    for(int i=0;i<ans.size();i++) printf("%d ",ans[i]);
    return 0;
}