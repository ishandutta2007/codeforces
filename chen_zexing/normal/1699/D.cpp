#pragma GCC optimize(3)
#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <climits>
#include <algorithm>
#include <complex>
#include <string.h>
#include <iomanip>
#include <assert.h>
#include <random>
#include <bitset>
using namespace std;
int a[5005],pre[5005];
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n,ans=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++){
            int cost=0,mx=0,oth=0,pos=0;
            for(int j=1;j<=n;j++){
                if(a[j]==i){
                    if(oth%2==0&&mx*2<=oth) {
                        cost += oth;
                        mx = oth = 0;
                        for (int k = pos + 1; k <= j; k++) pre[a[k]] = 0;
                        pos = j;
                    }
                    else{
                        pre[a[j]]++,oth++;
                    }
                }
                else{
                    pre[a[j]]++,oth++;
                    if(pre[a[j]]>mx) mx=pre[a[j]];
                }
            }
            //cout<<cost<<" "<<oth<<" "<<mx<<endl;
            for(int k=pos+1;k<=n;k++) pre[a[k]]=0;
            if(oth%2) oth++;
            if(mx*2>oth) oth=mx*2;
            cost+=oth;
            ans=max(ans,max(0,n-cost));
        }
        printf("%d\n",ans);
    }
    return 0;
}
//cf