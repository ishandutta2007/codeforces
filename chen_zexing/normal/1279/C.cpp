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
int a[100005],b[100005],dis[100005];
int main() {
    int T=1;
    cin>>T;
    while(T--){
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),dis[a[i]]=i;
        int mx=0;
        long long ans=0;
        for(int i=1;i<=m;i++){
            scanf("%d",&b[i]);
            if(dis[b[i]]>mx) ans+=(dis[b[i]]-i+1)*2-1;
            else ans++;
            mx=max(mx,dis[b[i]]);
        }
        cout<<ans<<endl;
    }
    return 0;
}