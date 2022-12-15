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
#define hash hassh
using namespace std;
int cnt[40005];
int main() {
    int T;
    cin>>T;
    while(T--){
        int a,b,q;
        cnt[0]=0;
        long long l,r;
        cin>>a>>b>>q;
        for(int i=1;i<=a*b;i++) {
            if (i % a % b != i % b % a)
                cnt[i] = cnt[i - 1] + 1;
            else cnt[i]=cnt[i-1];
        }
        while(q--){
            scanf("%lld%lld",&l,&r);
            long long ll=(l-1)/(a*b),rr=(r-1)/(a*b);
            if(ll==rr){
                long long t1=l%(a*b),t2=r%(a*b);
                if(t1==0) t1+=a*b;
                if(t2==0) t2+=a*b;
                long long ans=cnt[t2]-cnt[t1-1]; 
                printf("%lld ",ans);
                continue;
            }
            long long ans=(rr-ll-1)*cnt[a*b];
            long long t=l%(a*b);
            if(t==0) t+=a*b;
            ans+=cnt[a*b]-cnt[t-1];
            t=r%(a*b);
            if(t==0) t+=a*b;
            ans+=cnt[t];
            printf("%lld ",ans);
        }
        printf("\n");
    }
    return 0;
}