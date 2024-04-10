#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <assert.h>
#include <algorithm>
#include <stdlib.h>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <time.h>
#include <map>
#include <stack>
#include <unordered_set>
#include <bitset>
#include <list>
#define hash hassh
#define li __int128_t
#define ull unsigned long long
using namespace std;
int ans[105],f[105];
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n,a,b;
        scanf("%d%d%d",&n,&a,&b);
        if(a==b||a>b+1) puts("-1");
        else{
            memset(f,0,sizeof(f));
            memset(ans,0,sizeof(ans));
            f[a]=f[b]=1;
            ans[1]=a,ans[n/2+1]=b;
            int now=1;
            for(int i=n;i>=1;i--)
                if(ans[i]==0){
                    while(f[now]) now++;
                    ans[i]=now++;
                }
            int f=1;
            for(int i=1;i<=n/2;i++) if(ans[i]<a) f=0;
            for(int i=n/2+1;i<=n;i++) if(ans[i]>b) f=0;
            if(f) for(int i=1;i<=n;i++) printf("%d%c",ans[i],i==n?'\n':' ');
            else puts("-1");
        }
    }
    return 0;
}
//
/// 
//01
//