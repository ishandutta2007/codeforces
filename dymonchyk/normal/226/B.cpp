#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>

using namespace std;

int arr[100005];
long long sum[100005];

map <int,long long> f;

long long solve(int n,int k) {
    if (f.count(k)) return f[k];
    long long ret=0;
    long long cur=n-2; long long p=k;
    while(cur>=0) {
        ret+=sum[cur];
        cur-=p; p*=k;
    }
//  int r=(n-1)/k,l=(n-1)%k;
//  long long ret=(r>0 ? sum[r-1] : 0)*k;
//  ret+=sum[r+l]-(r>0 ? sum[r-1] : 0);
    return f[k]=ret;
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%d",&arr[i]);
    sort(arr,arr+n);
    sum[0]=arr[0];
    for(int i=1;i<n;++i)
        sum[i]=sum[i-1]+arr[i];
    int q,a;
    scanf("%d",&q);
    for(int i=0;i<q;++i) {
        scanf("%d",&a);
        if (i) printf(" ");
        printf("%I64d",solve(n,a));
    }
    printf("\n");
    return 0;
}