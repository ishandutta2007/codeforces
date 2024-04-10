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
int f[505],pre[505];
vector <int> v[505][2],ch[505];
vector <int> path;
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n,k;
        cin>>n>>k;
        if(n%2&&k%2==0){
            puts("-1");
            continue;
        }
        for(int i=1;i<=n;i++) v[0][0].push_back(i);
        queue <int> q;
        q.push(0);
        f[0]=1;
        while(!q.empty()){
            int temp=q.front();
            q.pop();
            for(int i=max(0,k-int(v[temp][1].size()));i<=min(k,int(v[temp][0].size()));i++){
                int tar=temp+i-(k-i),fl[505]={};
                if(!f[tar]){
                    pre[tar]=temp;
                    for(int j=0;j<v[temp][1].size();j++) fl[v[temp][1][j]]=1;
                    for(int j=0;j<i;j++) fl[v[temp][0][j]]^=1,ch[tar].push_back(v[temp][0][j]);
                    for(int j=0;j<k-i;j++) fl[v[temp][1][j]]^=1,ch[tar].push_back(v[temp][1][j]);
                    for(int j=1;j<=n;j++) v[tar][fl[j]].push_back(j);
                    q.push(tar),f[tar]=1;
                }
            }
        }
        int now=n;
        while(now) path.push_back(now),now=pre[now];
        int ans=0,t;
        for(int i=path.size()-1;i>=0;i--){
            printf("? ");
            for(int j=0;j<ch[path[i]].size();j++) printf("%d ",ch[path[i]][j]);
            puts("");
            fflush(stdout);
            scanf("%d",&t);
            ans^=t;
        }
        printf("! %d\n",ans);
    }
    return 0;
}
//
/// 
//01
// 
//
//dp