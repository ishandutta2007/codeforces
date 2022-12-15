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
int a[1000005],b[1000005];
int v[1000005];
int p[2][1000005];
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n,ans=0;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),b[i]=b[i-1]^a[i];
        for(int i=19;i>=0;i--){
            memset(p,-1,sizeof(p));
            int st=0;
            p[0][0]=0;
            for(int j=1;j<=n;j++){
                if((a[j]&(1<<i))==0) st=j,p[j%2][v[j]]=j;
                else{
                    if(p[j%2][v[j]]>=st) ans=max(ans,j-p[j%2][v[j]]);
                    else p[j%2][v[j]]=j;
                }
            }
            for(int j=1;j<=n;j++) v[j]+=((1<<i)&b[j]);
        }
        printf("%d\n",ans);
    }
    return 0;
}
//
/// 
//01
//