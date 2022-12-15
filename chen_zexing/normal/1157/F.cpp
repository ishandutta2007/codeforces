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
#define hash hassh
#define li __int128_t
#define ull unsigned long long
using namespace std;
int a[200005],cnt[200005];
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n,mx=0,ed=-1,now=0;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),cnt[a[i]]++;
        for(int i=1;i<=200000;i++){
            if(cnt[i]>=2){
                now+=cnt[i];
                if(now>mx) mx=now,ed=i;
            }
            else if(cnt[i]==1){
                now+=cnt[i];
                if(now>mx) mx=now,ed=i;
                now=1;
            }
            else now=0;
        }
        int st;
        for(int i=ed;i>=1;i--){
            if(i==1||(cnt[i]==1&&i!=ed)||cnt[i-1]==0){
                st=i;
                break;
            }
        }
        cout<<mx<<endl;
        for(int i=st;i<=ed;i++) printf("%d ",i);
        for(int i=ed;i>=st;i--) for(int j=1;j<cnt[i];j++) printf("%d ",i);
    }
    return 0;
}
//
/// 
//01
//