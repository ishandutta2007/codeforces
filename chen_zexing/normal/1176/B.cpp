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
int cnt[3];
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n;
        cin>>n;
        memset(cnt,0,sizeof(cnt));
        for(int i=1,x;i<=n;i++) scanf("%d",&x),cnt[x%3]++;
        int ans=cnt[0]+min(cnt[1],cnt[2]);
        int temp=min(cnt[1],cnt[2]);
        cnt[1]-=temp,cnt[2]-=temp;
        ans+=cnt[1]/3+cnt[2]/3;
        printf("%d\n",ans);
    }
    return 0;
}
//
/// 
//01
//