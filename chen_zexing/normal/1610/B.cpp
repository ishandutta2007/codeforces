#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <climits>
#include <algorithm>
#include <complex>
#include <string.h>
#include <iomanip>
#include <assert.h>
#include <random>
using namespace std;
int a[200005],b[200005];
int check(int x,int n){
    int m=0;
    for(int i=1;i<=n;i++)
        if(a[i]!=x)
            b[++m]=a[i];
    for(int i=1;i<=m/2;i++) if(b[i]!=b[m-i+1]) return 0;
    return 1;
}
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        int l=1,r=n,f=1;
        while(l<r){
            if(a[l]==a[r]){
                l++,r--;
                continue;
            }
            f=0;
            if(check(a[l],n)||check(a[r],n)) f=1;
            break;
        }
        puts(f?"YES":"NO");
    }
    return 0;
}