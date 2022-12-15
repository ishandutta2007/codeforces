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
vector <int> v[100005];
int l[100005],f[100005],mn[100005],mx[100005],pre[1000005];
int main() {
    int T=1;
    //cin>>T;
    while(T--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            scanf("%d",&l[i]);
            for(int j=0,t;j<l[i];j++) scanf("%d",&t),v[i].push_back(t);
        }
        for(int i=1;i<=n;i++){
            mn[i]=INT_MAX,mx[i]=INT_MIN;
            for(int j=0;j<l[i];j++) mn[i]=min(mn[i],v[i][j]),mx[i]=max(mx[i],v[i][j]);
            for(int j=1;j<l[i];j++)
                if(v[i][j]>v[i][j-1])
                    f[i]=1;
            if(!f[i]) pre[v[i][0]]++;
        }
        for(int i=1;i<=1000000;i++) pre[i]+=pre[i-1];
        long long ans=0;
        for(int i=1;i<=n;i++){
            if(f[i]){
                continue;
            }
            ans+=pre[v[i][l[i]-1]];
        }
        printf("%lld\n",1LL*n*n-ans);
    }
    return 0;
}