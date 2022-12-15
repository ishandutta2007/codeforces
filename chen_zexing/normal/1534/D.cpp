#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <assert.h>
#include <algorithm>
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
using namespace std;
int fa[2005],grand[2005],ans[2005][2005],n;
void query(int x){
    printf("? %d\n",x);
    fflush(stdout);
    for(int i=1;i<=n;i++) scanf("%d",&ans[x][i]);
}
void solve(int x){
    query(x);
    if(fa[x]==1){
        for(int i=1;i<=n;i++){
            if(ans[x][i]==1&&i!=1) fa[i]=x;
            if(ans[x][i]==2&&ans[1][i]==3) grand[i]=x,solve(i);
        }
    }
    else{
        for(int i=1;i<=n;i++){
            if(ans[grand[x]][i]==1&&ans[x][i]==1) fa[x]=i;
            if(ans[grand[x]][i]==3&&ans[x][i]==1) fa[i]=x;
            if(ans[grand[x]][i]==4&&ans[x][i]==2) grand[i]=x,solve(i);
        }
    }
}
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        cin>>n;
        query(1);
        int cnt[2]={};
        for(int i=2;i<=n;i++) cnt[ans[1][i]%2]++;
        if(cnt[1]<cnt[0]){
            for(int i=1;i<=n;i++) if(ans[1][i]==1) fa[i]=1,solve(i);
        }
        else{
            for(int i=1;i<=n;i++){
                if(ans[1][i]==1) fa[i]=1;
                else if(ans[1][i]==2) grand[i]=1,solve(i);
            }
        }
        puts("!");
        for(int i=2;i<=n;i++) printf("%d %d\n",fa[i],i);
    }
    return 0;
}
//
/// 
//01
// 
//
//dp