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
int a[100005],b[100005],c[100005],cnt[100005],ans[100005],now[100005],used[100005];
vector <int> v[100005];
int main() {
    int T=1;
    cin>>T;
    while(T--){
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),v[i].clear(),now[i]=0,used[i]=0,cnt[i]=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&b[i]);
            if(b[i]!=a[i]){
                v[b[i]].push_back(i);
                used[b[i]]=i;
            }
            else if(!used[b[i]]) used[b[i]]=i;
        }
        for(int i=1;i<=m;i++){
            scanf("%d",&c[i]);
            cnt[c[i]]++;
        }
        int f=1;
        for(int i=1;i<=n;i++)
            if(cnt[i]<v[i].size())
                f=0;
        //for(int i=1;i<=n;i++) cout<<cnt[i]<<" ";puts("");
        //cout<<cnt[c[m]]<<" "<<c[m]<<endl;
        if(used[c[m]]==0) f=0;
        if(!f){
            puts("NO");
            continue;
        }
        puts("YES");
        for(int i=m;i>=1;i--){
            if(i==m&&!v[c[i]].size()){
                ans[i]=used[c[i]];
                continue;
            }
            if(now[c[i]]<v[c[i]].size()){
                ans[i]=v[c[i]][now[c[i]]++];
            }
            else ans[i]=ans[m];
        }
        for(int i=1;i<=m;i++) printf("%d ",ans[i]);
        puts("");
    }
    return 0;
}