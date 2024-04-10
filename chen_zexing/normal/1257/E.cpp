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
int a[3][200005],n[3],cnt[3][200005],f[3][200005],mn[200005];
int main() {
    int T=1;
    //cin>>T;
    while(T--) {
        cin>>n[0]>>n[1]>>n[2];
        for(int i=0;i<3;i++)
            for(int j=1;j<=n[i];j++)
                scanf("%d",&a[i][j]),f[i][a[i][j]]=1;
        for(int i=0;i<3;i++)
            for(int j=1;j<=n[0]+n[1]+n[2];j++)
                cnt[i][j]=cnt[i][j-1]+f[i][j];
        /*
        for(int i=0;i<3;i++,puts(""))
            for(int j=0;j<=n[0]+n[1]+n[2];j++)
                printf("%d ",cnt[i][j]);
                */
        int ans=INT_MAX;
        mn[n[0]+n[1]+n[2]+1]=INT_MAX;
        for(int i=n[0]+n[1]+n[2];i>=0;i--) mn[i]=min(mn[i+1],cnt[2][i]-cnt[1][i]);
        for(int i=0;i<=n[0]+n[1]+n[2];i++) ans=min(ans,cnt[1][i]+cnt[0][n[0]+n[1]+n[2]]-cnt[0][i]+cnt[1][n[0]+n[1]+n[2]]+mn[i]);
        cout<<ans<<endl;
    }
    return 0;
}
//
/// 
//01
// 
//
//dp