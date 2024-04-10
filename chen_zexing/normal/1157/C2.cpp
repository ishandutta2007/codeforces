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
        int n,st=-1;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n+1;i++){
            if(i!=n+1&&!cnt[a[i]]&&a[i]>a[i-1]) cnt[a[i]]++;
            else{
                st=i-1;
                break;
            }
        }
        int nowr=n+1,ll=st,rr=n+1,now=st,mx=0;
        for(int i=st;i>=0;i--){
            while(cnt[a[nowr-1]]==0&&a[nowr-1]>a[nowr]) nowr--,cnt[a[nowr]]++,now++;
            if(now>mx) mx=now,rr=nowr,ll=i;
            now--,cnt[a[i]]--;
        }
        printf("%d\n",mx);
        int tl=1,tr=n;
        for(int i=1;i<=ll+n-rr+1;i++){
            if(tl>ll) printf("R"),tr--;
            else if(tr<rr) printf("L"),tl++;
            else{
                if(a[tl]<a[tr]) printf("L"),tl++;
                else printf("R"),tr--;
            }
        }
    }
    return 0;
}
//
/// 
//01
//