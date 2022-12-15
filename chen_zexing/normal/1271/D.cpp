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
int a[5005],b[5005],c[5005],av[5005];
vector <int> v[5005];
int dp[5005][5005];
struct node{
    int v;
    friend bool operator <(node a,node b){
        return a.v>b.v;
    }
};
priority_queue <node> q;
int lst[5005];
int main() {
    int T=1;
    //cin>>T;
    while(T--){
        int n,m,k;
        cin>>n>>m>>k;
        for(int i=1;i<=n;i++) scanf("%d%d%d",&a[i],&b[i],&c[i]);
        int now=k,f=1;
        for(int i=1;i<=n;i++){
            lst[i]=i;
            if(now<a[i]){
                f=0;
                break;
            }
            now+=b[i];
        }
        if(!f){
            puts("-1");
            continue;
        }
        for(int i=1;i<=m;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            lst[y]=max(lst[y],x);
        }
        for(int i=1;i<=n;i++) v[lst[i]].push_back(c[i]);
        int ans=0;
        now=k;
        for(int i=1;i<=n;i++){
            while(now<a[i]){
                ans-=q.top().v;
                q.pop();
                now++;
            }
            now+=b[i];
            for(int j=0;j<v[i].size();j++){
                ans+=v[i][j];
                q.push(node{v[i][j]});
                now--;
            }
        }
        while(now<0){
            ans-=q.top().v;
            q.pop();
            now++;
        }
        cout<<ans<<endl;
    }
    return 0;
}