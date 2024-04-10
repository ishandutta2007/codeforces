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
int a[400005],cnt[1000005],b[400005];
int main() {
    int T=1;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) cnt[i]=0;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),b[i]=a[i];
        sort(b+1,b+n+1);
        for(int i=1;i<=n;i++) a[i]=lower_bound(b+1,b+n+1,a[i])-b,cnt[a[i]]++;
        int sum=0,c=0,p,t1=0,t2=0,t3=0;
        for(int i=n;i>=1;i--){
            if(cnt[i]){
                p=i;
                t1=cnt[p];
                break;
            }
        }
        for(int i=p-1;i>=1;i--){
            if(t2>t1){
                p=i+1;
                break;
            }
            t2+=cnt[i];
        }
        for(int i=p-1;i>=1;i--){
            if(t3>t1&&t1+t2+t3+cnt[i]>n/2) break;
            t3+=cnt[i];
        }
        if(t2<=t1||t3<=t1||t1+t2+t3>n/2) puts("0 0 0");
        else printf("%d %d %d\n",t1,t2,t3);
    }
    return 0;
}