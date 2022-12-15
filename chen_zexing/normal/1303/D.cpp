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
int cnt[100],nd[100];
int main() {
    int T=1;
    cin>>T;
    while(T--) {
        long long n,m;
        long long tot=0;
        cin>>n>>m;
        memset(nd,0,sizeof(nd));
        memset(cnt,0,sizeof(cnt));
        for(long long i=1,t;i<=m;i++){
            scanf("%lld",&t);
            tot+=t;
            int c=0;
            while(t%2==0) t/=2,c++;
            cnt[c]++;
        }
        if(tot<n){
            puts("-1");
            continue;
        }
        int now=0;
        while(n){
            nd[now++]=n%2;
            n>>=1;
        }
        int ans=0;
        for(int i=0;i<63;i++){
            //cout<<i<<" "<<cnt[i]<<" "<<nd[i]<<endl;
            if(cnt[i]<nd[i]){
                nd[i]-=cnt[i];
                cnt[i]=0;
                ans++;
                nd[i+1]+=(nd[i]+1)/2;
            }
            else {
                cnt[i]-=nd[i];
                if (cnt[i]) cnt[i + 1] += cnt[i] / 2;
            }
            //cout<<ans<<endl;
        }
        printf("%d\n",ans);
    }
    return 0;
}
//
/// 
//01
// 
//
//dp