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
#define li __int128_t
using namespace std;
int a[105],b[105],oth[205],f[205],vis[205];
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n,k,ans=0,cnt=0;
        cin>>n>>k;
        int r=n-k;
        for(int i=1;i<=n*2;i++) f[i]=0;
        for(int i=1;i<=k;i++) scanf("%d%d",&a[i],&b[i]),oth[a[i]]=b[i],oth[b[i]]=a[i],f[a[i]]=f[b[i]]=1;
        for(int i=1;i<=n*2;i++){
            if(f[i]==0){
                cnt++;
                if(cnt>r) break;
                int temp=0;
                for(int j=i+1;j<=n*2;j++){
                    if(f[j]==0) temp++;
                    if(temp==r){
                        oth[i]=j,oth[j]=i;
                        break;
                    }
                }
            }
        }
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n*2;i++){
            if(!vis[i]){
                vis[i]=vis[oth[i]]=1;
                int now=0;
                for(int j=i+1;j<oth[i];j++){
                    if(oth[j]>oth[i]||oth[j]<i) now++;
                }
                ans+=now;
            }
        }
        printf("%d\n",ans/2);
    }
    return 0;
}
//
/// 
//01
// 
//
//dp
//