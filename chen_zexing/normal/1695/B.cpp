#pragma GCC optimize(3)
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
#include <bitset>
using namespace std;
int a[55];
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        if(n%2){
            puts("Mike");
            continue;
        }
        long long t1=LLONG_MAX,t2=LLONG_MAX;
        for(int i=1;i<=n;i+=2) t1=min(t1,1LL*(a[i]-1)*n/2+(i+1)/2);
        for(int i=2;i<=n;i+=2) t2=min(t2,1LL*(a[i]-1)*n/2+i/2);
        puts(t1>t2?"Mike":"Joe");
    }
    return 0;
}
//cf