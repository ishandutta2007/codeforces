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
int a[100005],b[100005];
long long pre[100005];
int main() {
    int sum=0,n,x=0;
    cin>>n;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]),sum+=a[i];
    for(int i=1;i<=n;i++) if(a[i]) b[++x]=i;
    for(int i=1;i<=x;i++) pre[i]=pre[i-1]+b[i];
    if(sum<=1){
        puts("-1");
        return 0;
    }
    int p=0;
    long long ans=LLONG_MAX;
    for(int t=2;t<=n;t++)
        if(sum%t==0){
            long long temp=0;
            p=t;
            for(int i=1;i<=x/p;i++) {
                int st = (i - 1) * p + 1, ed = st + p - 1;
                long long mn = LLONG_MAX;
                //cout<<st<<" "<<ed<<endl;
                for (int j = st; j <= ed; j++) {
                    long long cnt = pre[ed] - pre[j] - 1LL * (ed - j) * b[j] + 1LL * (j - st) * b[j] -
                                    (pre[j - 1] - pre[st - 1]);
                    mn = min(mn, cnt);
                }
                temp += mn;
            }
            ans=min(ans,temp);
        }
    cout<<ans<<endl;
    return 0;
}