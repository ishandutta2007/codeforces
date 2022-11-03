#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <memory.h>

using namespace std;

int arr[2000006];
long long sum[2000006];

long long get(int l,int r) {
    if (l>r) return 0;
    return sum[r]-(l>0 ? sum[l-1] : 0);
}

double solve(int n,int l,int t) {
    double ret=0;
    int last=0,tot=n,val=2*t%l;
    sum[0]=arr[0];
    for(int i=1;i<n;++i) sum[i]=sum[i-1]+arr[i];
    for(int i=0;i<n;++i) {
        while(last+1<tot&&2*t>=(arr[last+1]-arr[i])) ++last;
        int L=i,R=last+1;
        while(R-L>1) {
            int M=(L+R)>>1;
            if (arr[M]-arr[i]<=val) L=M;
            else R=M;
        }
        long long cnt=last-i,Sum=2LL*t*cnt;
            Sum-=(get(i,last)-1LL*arr[i]*cnt);
            Sum-=(1LL*val*(L-i)-get(i,L)+1LL*arr[i]*(L-i));
            Sum-=(1LL*(last-L)*(val+l)-get(L+1,last)+1LL*arr[i]*(last-L));
        arr[tot]=arr[i]+l; sum[tot]=sum[tot-1]+arr[tot];
        ++tot;
        long long add=Sum/l+(last-i);
        ret+=add/4.0;
    }
    return ret;
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,l,t;
    scanf("%d%d%d",&n,&l,&t);
    for(int i=0;i<n;++i)
        scanf("%d",&arr[i]);
    double ans=solve(n,l,t);
//  for(int i=0;i<n;++i)
//      arr[i]=l-arr[i];
//  reverse(arr,arr+n);
//  ans+=solve(n,l,t);
    printf("%.7lf\n",ans);
    return 0;
}