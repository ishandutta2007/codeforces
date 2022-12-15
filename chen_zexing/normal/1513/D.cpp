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
int a[200005],id[200005],f[200005],tl[200005],tr[200005];
bool cmp(int x,int y){
    return a[x]<a[y];
}
int main() {
    int T=1;
    cin>>T;
    while(T--){
        int n,p;
        cin>>n>>p;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),id[i]=i,f[i]=0,tl[i]=tr[i]=p;
        sort(id+1,id+n+1,cmp);
        long long ans=1LL*(n-1)*p;
        for(int i=1;i<=n;i++){
            int temp=id[i];
            if(f[temp]) continue;
            if(a[temp]>=p) break;
            f[temp]=1;
            int now=temp+1;
            while(now<=n&&a[now]%a[temp]==0){
                if(tl[now]==p) ans-=p-a[temp],tl[now]=0,tr[now-1]=0;
                now++,f[now-1]=1;
            }
            now=temp-1;
            while(now&&a[now]%a[temp]==0){
                if(tr[now]==p) ans-=p-a[temp],tr[now]=0,tl[now+1]=0;
                now--,f[now+1]=1;
            }
            //cout<<ans<<endl;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
//
/// 
//01
// 
//
//dp