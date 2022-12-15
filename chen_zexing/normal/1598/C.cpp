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
int a[200005];
map <long long,int> mp;
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n;
        long long sum=0;
        cin>>n;
        mp.clear();
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),a[i]*=2,sum+=a[i],mp[a[i]]++;
        if(sum%n) puts("0");
        else{
            long long tar=sum/n;
            sort(a+1,a+n+1);
            n=unique(a+1,a+n+1)-a-1;
            long long ans=0;
            for(int i=1;i<=n;i++) ans+=1LL*mp[a[i]]*mp[tar*2-a[i]];
            ans-=mp[tar],ans/=2;
            printf("%lld\n",ans);
        }
    }
    return 0;
}
//
/// 
//01
//