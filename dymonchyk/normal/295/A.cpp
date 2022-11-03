#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <ctime>
#include <cmath>
#include <set>
#include <map>

using namespace std;

long long ans[100005];
int l[100005],r[100005],d[100005];
int sum[100005],a[100005];

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<n;++i)
        scanf("%d",&a[i]);
    for(int i=0;i<m;++i) {
        scanf("%d%d%d",&l[i],&r[i],&d[i]); --l[i],--r[i];
    }
    int x,y;
    for(int i=0;i<k;++i) {
        scanf("%d%d",&x,&y); --x,--y;
        sum[x]++; sum[y+1]--;
    }
    int cnt=0;
    for(int i=0;i<m;++i) {
        cnt+=sum[i];
        ans[l[i]]+=1LL*cnt*d[i];
        ans[r[i]+1]-=1LL*cnt*d[i];
    }
    long long cur=0;
    for(int i=0;i<n;++i) {
        cur+=ans[i];
        ans[i]=cur;
    }
    for(int i=0;i<n;++i) {
        if (i) printf(" ");
        printf("%I64d",a[i]+ans[i]);
    }
    printf("\n");
    return 0;
}