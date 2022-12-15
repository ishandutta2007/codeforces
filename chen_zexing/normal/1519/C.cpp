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
vector <long long> v[200005],s[200005];
long long u[200005],a[200005],id[200005];
bool cmp(long long a,long long b){
    return a>b;
}
bool cmp2(long long a,long long b){
    return v[a].size()<v[b].size();
}
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) v[i].clear(),s[i].clear(),id[i]=i;
        for(int i=1;i<=n;i++) scanf("%lld",&u[i]);
        for(int i=1;i<=n;i++){
            scanf("%lld",&a[i]);
            v[u[i]].push_back(a[i]);
        }
        for(int i=1;i<=n;i++) if(v[i].size()){
                sort(v[i].begin(),v[i].end(),cmp);
            }
        sort(id+1,id+n+1,cmp2);
        for(int i=1;i<=n;i++) {
            long long sum=0;
            for (int j = 0; j < v[i].size(); j++) sum+=v[i][j],s[i].push_back(sum);
        }
        int l=1;
        for(int i=1;i<=n;i++){
            while(l<=n&&v[id[l]].size()<i) l++;
            long long ans=0;
            for(int j=l;j<=n;j++) ans+=s[id[j]][v[id[j]].size()/i*i-1];
            printf("%lld ",ans);
        }
        puts("");
    }
    return 0;
}
//
/// 
//01
// 
//
//dp