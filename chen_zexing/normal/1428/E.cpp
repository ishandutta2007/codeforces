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
struct carrot{
    int l,cnt;
    long long change(){
        long long c1=1LL*(l/cnt)*(l/cnt)*(cnt-l%cnt)+1LL*(l/cnt+1)*(l/cnt+1)*(l%cnt);
        cnt++;
        long long c2=1LL*(l/cnt)*(l/cnt)*(cnt-l%cnt)+1LL*(l/cnt+1)*(l/cnt+1)*(l%cnt);
        cnt--;
        return c1-c2;
    }
    friend bool operator <(carrot a,carrot b){
        return a.change()<b.change();
    }
};
int a[100005];
priority_queue <carrot> q;
int main() {
    int T=1;
    //cin>>T;
    while(T--) {
        int n,k;
        cin>>n>>k;
        long long ans=0;
        for(int i=1;i<=n;i++)  scanf("%d",&a[i]),ans+=1LL*a[i]*a[i],q.push(carrot{a[i],1});
        k-=n;
        while(k--){
            carrot t=q.top();
            q.pop();
            ans-=t.change();
            t.cnt++;
            q.push(t);
        }
        printf("%lld\n",ans);
    }
    return 0;
}