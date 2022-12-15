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
int a[200005],b[200005],c[200005],x[200005],y[200005];
vector <int> v[200005];
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n,m,f=0;
        cin>>n>>m;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),v[i].clear(),c[i]=0;
        for(int i=1;i<=n;i++) scanf("%d",&b[i]);
        for(int i=1;i<=m;i++) scanf("%d%d",&x[i],&y[i]),v[x[i]].push_back(y[i]),v[y[i]].push_back(x[i]);
        c[1]=1;
        queue <int> q;
        q.push(1);
        while(!q.empty()){
            int temp=q.front();
            q.pop();
            for(int i=0;i<v[temp].size();i++){
                if(c[v[temp][i]]==0) c[v[temp][i]]=3-c[temp],q.push(v[temp][i]);
                else if(c[v[temp][i]]==c[temp]) f=1;
            }
        }
        if(f){
            long long sum=0;
            for(int i=1;i<=n;i++) sum+=abs(a[i]-b[i]);
            puts(sum%2?"NO":"YES");
        }
        else{
            long long sum[2]={};
            for(int i=1;i<=n;i++) sum[c[i]%2]+=a[i]-b[i];
            puts(sum[0]==sum[1]?"YES":"NO");
        }
    }
    return 0;
}
//
/// 
//01
// 
//
//dp